/*
 * CS 261 Data Structures
 * Assignment 5
 * Name: Amy Stockinger
 * Date: 2/19/19
 */

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Copied/Source: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
Accepts two strings and returns Levenshtein distance between them
*/
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return(column[s1len]);
}


/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    char *word = nextWord(file);
    while(word != NULL){
        hashMapPut(map, word, 1);
        free(word);
        word = nextWord(file);
    }
    free(word);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int ch;
    int quit = 0;
    int notValid = 0;

    while (!quit){ 
        int i = 0;
        printf("Enter a word or \"quit\" to quit: ");
        while((ch = getchar()) != '\n'){
            inputBuffer[i++] = ch;
        }
        inputBuffer[i] = '\0';
        i = 0;
        while(inputBuffer[i] != '\0' && inputBuffer[i] != '\n'){
            if(inputBuffer[i] == ' ' || ((inputBuffer[i] < 'a' || inputBuffer[i] > 'z') && (inputBuffer[i] < 'A' || inputBuffer[i] > 'Z'))){
                printf("Please enter one word using only letters.\n");
                notValid = 1;
                break;
            }
            i++;
        }

        if (strcmp(inputBuffer, "quit") == 0 || notValid == 1){
            quit = 1;
        }
        else{
            char wordCheck[256]; 
            strcpy(wordCheck, inputBuffer);                                           // copy input
            
            int count = 0;
            while(wordCheck[count] != '\0'){
                if(wordCheck[count] >= 'A' && wordCheck[count] <= 'Z'){
                    wordCheck[count] += 32;                                           // make it all lower case
                }
                count++;
            }
            wordCheck[count] = '\0';                          
            if(hashMapContainsKey(map, wordCheck)){                                   // check for key with lowercase copy
                printf("The inputted word %s is spelled correctly.\n", inputBuffer);  // print back the original word in result
            }
            else{
                printf("The inputted word %s is spelled incorrectly.\n", inputBuffer);
                printf("Did you mean:\n");
                int suggestions = 5;
                // hash link pointer array to store word "key" and distance "value" for 5 words
                HashLink **suggestedWords = malloc(suggestions * sizeof(HashLink *));
                for(int i = 0; i < suggestions; i++){
                    suggestedWords[i] = NULL;
                }
                // search entire dictionary for suggestions
                for(int i = 0; i < map->capacity; i++){
                    HashLink *itr = map->table[i];
                    while(itr != NULL){
                        // get distance compared to each word in this list
                        int dist = levenshtein(wordCheck, itr->key);
                        // compare to suggestion array until the word is added to it, or the word dist is too large to qualify
                        for(int i = 0; i < suggestions; i++){
                            // if there is an open spot, fill it
                            if(suggestedWords[i] == NULL){
                                suggestedWords[i] = malloc(sizeof(HashLink));
                                suggestedWords[i]->key = malloc(sizeof(char) * 256);  // keep key sizes uniform as they can change
                                strcpy(suggestedWords[i]->key, itr->key);
                                suggestedWords[i]->value = dist;
                                break;
                            }
                            // compare to suggestion array, and stop if it is put into the array
                            else if(dist < suggestedWords[i]->value){
                                strcpy(suggestedWords[i]->key, itr->key);
                                suggestedWords[i]->value = dist;
                                break;
                            }
                        }
                        itr = itr->next;
                    }
                }
                // print final list of suggested words
                for(int i = 0; i < suggestions; i++){
                    printf("%s\n", suggestedWords[i]->key);
                }
                printf("\n");
                // deallocate list
                for(int i = 0; i < suggestions; i++){
                    free(suggestedWords[i]->key);
                    free(suggestedWords[i]);
                }
                free(suggestedWords);
            }
            strcpy(inputBuffer, "");
        }
    }
    hashMapDelete(map);
    return 0;
}