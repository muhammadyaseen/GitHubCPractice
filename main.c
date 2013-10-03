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
    
    printf("\nLargest Palindrome product : %d \n", largestPalindromeProduct());
    
    printf("\nSum of primes is : %d\n", primesSum(41));
    
    printf("\nAmicable Number sum is : %d\n", amicableNumbers());

    strncatt("Greetings! ","To all and To Me", 6);
    
    printf("\nTrucatable Primes Sum is : %ld\n", sumTruncatablePrimes());
    
    return 0;
  
}

