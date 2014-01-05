/* 
 * This is the file where we 'call' all the implemented functions
 * As such it should not have any function declaration or logic code.
 * Function declaration and prototype should go in library.h file.
 * Use this file to test your functions
 */

 // Ladder of #includes
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include "library.h"

int main(int argc, char** argv) {
    
    char dest[L], src[L];
    int n;
    
    printf("\nEven Fabonacci sum : %d \n", evenFibonnaciTermsSum(4000000));
    
    printf("\nLargest Palindrome product : %d \n", largestPalindromeProduct());
    
    printf("\nSum of primes is : %d\n", primesSum(41));
    
    printf("\nAmicable Number sum is : %d\n", amicableNumbers());
    
    sumFactorialDigits(13);

    printf("\nTrucatable Primes Sum is : %ld\n\n", sumTruncatablePrimes());
    
    puts("\nEnter Destination String: ");
    gets(dest);
    
    puts("\nEnter Source String: ");
    gets(src);
    
    puts("\nEnter n: ");
    scanf("%d",&n);
    
    strncatt(dest, src, n);
    
    char * s1 = (char *)malloc(100);
    
    puts("\nEnter String to be reveresed: ");
    
    gets(s1);
    
    printf("\n Deleted : %s", (strdel(s1,2)));
    
    char * s2 = (char *)malloc(100);
    
    printf("\n Reversed : %s \n", strReverse(s2,s1));
  
    return 0;
}

