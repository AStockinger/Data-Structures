/*********************************************************************
** Program Filename: stackapp.c
** Author: Amy Stockinger
** Date: 1/12/2019
** Description: Application that uses a stack to check string input
** balance for {}, [], ()
** Input: a string
** Output: a message displaying the string and confirming if it
** is balanced or not
*********************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	s is not null
	post:	1 if balanced, 0 is unbalanced
*/
int isBalanced(char* s)
{
	if(s == NULL){
		return 1;
	}

	char n = nextChar(s);
	DynArr *stack;
	stack = newDynArr(8);					// make a stack to hold relevant chars

	while(n != '\0'){						// cycle through given string
		if(n == '['){						// check for releveat chars
			pushDynArr(stack, ']');			// push complement on stack if found
		}
		else if(n == '('){
			pushDynArr(stack, ')');
		}
		else if(n == '{'){
			pushDynArr(stack, '}');
		}
		else if(n == topDynArr(stack)){		// relevant char complements to be popped off
			popDynArr(stack);				// in the reverse order they are found, making them balanced
		}
		n = nextChar(s);
	}

	if(isEmptyDynArr(stack) == 1){			// only balanced if stack of relevant chars is empty
		deleteDynArr(stack);
		return 1;
	}
	else{
	deleteDynArr(stack);
	return 0;	
	}		
}

int main(int argc, char* argv[]){
	
	char* s= argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

