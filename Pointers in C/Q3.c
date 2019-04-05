/* CS261- Assignment 1 - Q.3*/
/* Name: Amy Stockinger
 * Date: 01/14/19
 * Solution description:
 * 
 * source for scanf to allow spaces:
 * https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf
 */

#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
	if((ch >= 'a') && (ch <= 'z')){
		ch -= 32;
	}
	return ch;
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
	if((ch >= 'A') && (ch <= 'Z')){
		ch += 32;
	}
	return ch;
}

int stringLength(char s[]) {
   /*Return the length of the string*/
   int length = 0;

	for(int i = 0; s[i] != '\0'; i++){
		length++;
	}
   return length;
}

void camelCase(char* word){
	/*Convert to camelCase*/
	int length = stringLength(word);
	int charsInMiddle = 0;

	// change all special chars to underscores and all aplhabetic chars to lowercase
	for(int i = 0; i < length; i++){
		if(word[i] != '_' && (word[i] < 'a' || word[i] > 'z') && (word[i] < 'A' || word[i] > 'Z')){
			word[i] = '_';
		}
		word[i] = toLowerCase(word[i]);
	}

	// skip characters before the first word and after last word
	while(charsInMiddle == 0){
		if(word[0] == '_'){								// get rid of underscores from index 0
			for(int j = 0; word[j + 1] != '\0'; j++){
				word[j] = word[j + 1];
			}
			word[length - 1] = '\0';					// adjust word length
			length--;
		}
		else if(word[length - 1] == '_'){				// get rid of underscores from last index
			word[length - 1] = '\0';					// adjust word length
			length--;
		}
		else{
			charsInMiddle = 1;
		}
	}

	// gets rid of underscores and makes next letter uppercase
	for(int i = 0; word[i + 1] != '\0'; i++){
		if(word[i] == '_'){
			word[i + 1] = toUpperCase(word[i + 1]);		// next letter uppercase
			for(int j = i; word[j + 1] != '\0'; j++){	// get rid of underscore
				word[j] = word[j + 1];
			}
			if(i > 0){									// make sure no space is skipped
				i--;
			}
			word[length - 1] = '\0';					// adjust final length
			length--;
		}
	}
}

int main(){
	/*Read the string from the keyboard*/
	char word[80];
	printf("Please enter a string less than 80 characters.\n");
	scanf("%79[^\n]%*c", word);

    // validate input
    int lastIndex = 0;
	int length = stringLength(word);
    int oneWord = 0, spacePresent = 0, isValid = 0;						// "bools"

    // check for alphabetical character for first grouping
    for(int i = 0; i < length; i++){
        if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
            oneWord = 1;
            lastIndex = i;
            break;
        }
    }
    // per Piazza, in between groupings should be non-alphabetical characters
    for(int i = lastIndex; i < length; i++){
        if((word[i] < 'a' || word[i] > 'z') && (word[i] < 'A' || word[i] > 'Z')){
            spacePresent = 1;
            lastIndex = i;
            break;
        }
    }
    // check for alphabetical character for second grouping
    for(int i = lastIndex; i < length; i++){
        if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
            if(oneWord == 1 && spacePresent == 1){
                isValid = 1;
                break;
            }
        }
    }

	// print message if invalid string input, otherwise camelCase
	if(isValid == 0){
		printf("Invalid string input.\n");
	}
	else{
		/*Call camelCase*/
		camelCase(word);

		/*Print the new string*/
		printf("%s \n", word);
	}
	return 0;
}