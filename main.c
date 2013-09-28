/* 
 * This is the file where we 'call' all the implemented functions
 * As such it should not have any function declaration or logic code.
 * Function declaration and prototype should go in library.h file.
 * Use this file to test your functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include "library.h"

int main(int argc, char** argv) {
    
    printf("\nEven Fabonacci sum : %d \n", evenFibonnaciTermsSum(4000000));
    
    return 0;
    
}

