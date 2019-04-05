/*****************************************************************************
 * Author: Amy Stockinger
 * Date Created: 01/05/2019
 * Last Modification Date: 01/05/2019
 * Filename: Assignment0.c
 *
 * Overview: This program calculates the area of a triangle using Heron's
 * formula.
 *
 * Input: The user is prompted to enter the lengths of each side of the
 * triangle for caluclation. The user may enter double percision floating-point
 * numbers.
 *
 * Output: The program will print the double percision floating-point area
 * of the triangle.
 ****************************************************************************/

#include <stdio.h>
#include <math.h>

// function takes 3 triangle side lengths as arguments and prints the calculated area
void CalculateArea(double a, double b, double c)
{
    double area, s;
    
    s = (a + b + c) / 2;                                     // Heron's formula
    area = sqrt((s * (s - a) * (s - b) * (s - c)));
    
    printf("The area of your triangle is: %lf \n", area);    // display results
}

// main function prompts user for triangle lengths and calls function to print area
int main()
{
    double side1, side2, side3;                              // variables for side lengths
    
    printf("Please enter the length of side a: ");           // get values from user
    scanf("%lf", &side1);
    printf("Please enter the length of side b: ");
    scanf("%lf", &side2);
    printf("Please enter the length of side c: ");
    scanf("%lf", &side3);

    CalculateArea(side1, side2, side3);                      // calculate with Heron's formula

    return 0;
}