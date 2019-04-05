/* CS261- Assignment 1 - Q.1*/
/* Name: Amy Stockinger
 * Date: 01/08/19
 * Solution description:
 *
 * Source for shuffle array of ID numbers:
 * https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *studentPtr = (struct student *) malloc(10 * (sizeof(struct student)));

     /*Return the pointer*/
     return studentPtr;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
    IDs being between 1 and 10, scores between 0 and 100*/
    int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // make array to shuffle IDs

    for(int i = 9; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = ids[i];                           // swap
        ids[i] = ids[j];
        ids[j] = temp;
    }

    for(int i = 0; i < 10; i++){
        int randScore = rand() % 101;
        students[i].score = randScore;              // assign scores and ids
        students[i].id = ids[i];
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    for(int i = 0; i < 10; i++){
        printf("ID: %d  Score: %d \n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
    ten students*/
    int min = 100, max = 0, avg = 0;

    for(int i = 0; i < 10; i++){
        if(students[i].score < min){
            min = students[i].score;
        }
        if(students[i].score > max){
            max = students[i].score;
        }
        avg += students[i].score;
    }
    avg /= 10;                                        // divide avg by 10 to make it an average

    printf("The minimum score is: %d \n", min);
    printf("The maximum score is: %d \n", max);
    printf("The average score is: %d \n", avg);
     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;
    srand(time(NULL));
    
    /*Call allocate*/
    stud = allocate();
    
    /*Call generate*/
    generate(stud);
    
    /*Call output*/
    output(stud);
    
    /*Call summary*/
    summary(stud);
    
    /*Call deallocate*/
    deallocate(stud);

    return 0;
}