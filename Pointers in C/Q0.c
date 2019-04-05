/* CS261- Assignment 1 - Q. 0*/
/* Name: Amy Stockinger
 * Date: 01/08/19
 * Solution description: 
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
     printf("The value of the integer is: %d \n", *iptr);
     printf("The address of the integer is: %p \n", iptr);
          
     /*Increment the value of the integer pointed to by iptr by 5*/
     *iptr += 5;
          
     /*Print the address of iptr itself*/
     printf("The address of the integer pointer iptr is: %p \n", &iptr);

    /*Dummy variable, ignore the warning*/
   int c=5;  
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
     printf("The value of the integer is: %d \n", *jptr);
     printf("The address of the integer is: %p \n", jptr); 

     /*Decrement the address by 1 pointed to by jptr using jptr */
     jptr -= 1;
      
     /*Print the address of jptr itself*/
     printf("The address of the integer pointer jptr is: %p \n", &jptr);

}


int main(){
    srand(time(NULL));

    /*Declare an integer x and initialize it randomly to a value in [0,10]*/
    int x = rand() % 11;
    
    /*Print the value and address of x*/
    printf("The value of x is: %d \n", x);
    printf("The address of x is: %p \n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("The value of x is: %d \n", x);

    /* QUESTION 1.) After calling fooA, is the value of x different than before? Why?
        Yes, it increased by 5 because the variable was passed by reference, and incremented
    the value of x using the reference.
    */
    
    /*Call fooB() with the address of x*/
    fooB(&x);
    
    /*Print the value and address of x*/
    printf("The value of x is: %d \n", x);
    printf("The address of x is: %p \n", &x);

    /* QUESTION 2.) After calling fooB, are the address and value of x different than before? Why?
        The value and address of x are the same because we changed the address a pointer was 
        pointing to, not x.
    */
    
    return 0;
}


