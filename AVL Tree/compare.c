#include <stdio.h>
#include "assert.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater than, less than, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.
 
 if left < right return -1
 if left > right return 1
 if left = right return 0
 */
int compare(void *left, void *right)
{
	struct data *ml,*mr;
	/* Casts! */
	ml = (struct data *)left;
	mr = (struct data *) right;
  /* Function to compare to 'data' types ...currently a number and name */
	
  if(ml->number < mr->number) return -1;
  if(ml->number > mr->number) return 1;

  return 0;
}

void printVal (void *val)
{
	struct data * myVal = (struct data *)val;
	printf("%d ", myVal->number); 
}



