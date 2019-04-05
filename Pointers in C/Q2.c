/* CS261- Assignment 1 - Q.2*/
/* Name: Amy Stockinger
 * Date: 01/08/19
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int *temp = a;
    a = b;
    b = temp;
    
    /*Decrement the value of integer variable c*/
    c--;
    
    /*Return c*/
    return c;
}

int main(){
    srand(time(NULL));

    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 11, y = rand() % 11, z = rand() % 11;
    
    /*Print the values of x, y and z*/
    printf("The value of x is: %d \n", x);
    printf("The value of y is: %d \n", y);
    printf("The value of z is: %d \n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int someNum = foo(&x, &y, z);
    
    /*Print the values of x, y and z*/
    printf("The value of x is: %d \n", x);
    printf("The value of y is: %d \n", y);
    printf("The value of z is: %d \n", z);
    
    /*Print the value returned by foo*/
    printf("The value returned by foo is: %d \n", someNum);
    
    return 0;
}
    
/* QUESTION 1) Is the return value different than the value of integer z? Why or why not?
        Yes, the return value is different because z is not passed by reference, so the function
    cannot change it, but it can return one less than the value passed into the function.

   QUESTION 2) Are the values of integers x and y different before and after calling the 
   function foo(..)? Why or why not?
    No, the values remain the same. I interpreted the directions to mean 'swap the addresses of 
    what the pointers point to', which would not affect the values at the addresses themselves.
*/
    


