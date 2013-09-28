// PRE PROCESSOR DIRECTIVES
#define TRUE 0

// START FUNCTION PROTOTYEOPES

int evenFibonnaciTermsSum(int);
int largestPalindromeProduct(void);
int primesSum(int);
void amicableNumbers();
int isPalindrome(int);
int isPrime(int);


// END FUNCTION PROTOTYPES

//START FUNCTION DECLARATIONS

/* Below is an example function declaration, please don't delete it and follow the same pattern for your functions.
 * suggestions are welcome (variable and function name is irrelevant)
 */

/* @descripton - Brief description what the function is intended to do, or how it integrates into the larger project
 * 
 * @param myArg1 - A short message which makes purpose/use of myArg1 clear to reader
 * @param myArg2 - A short message which makes purpose/use of myArg1 clear to reader
 * @param myArg2 - A short message which makes purpose/use of myArg1 clear to reader
 * 
 * @returns - A message which describes what this function returns e.g 'Address of myArg2 in myArg3'
 * @note - Any special note for example array bounds, limitations, cases where function fails should go here, brief and short
 */
//void SomeAwesomeFunction(int myArg1, char myArg2, char * myArg3)
//{
//
//
//}

/* @descripton - Calculates the sum of terms of Fibonacci Sequence.
 * 
 * @param limit - Upper limit which the sum shouldn't exceed
 * 
 * @returns - Sum of terms, where sum is always less than or equal to limit
 * @note - first two terms of fibonacci sequence are 0 and 1 respectively, nth term is sum or (n-1)th and (n-2)th term, n > or = 2
 */

int evenFibonnaciTermsSum(int limit)
{
    int sum  = 0;
    int firstTerm = 0, secondTerm = 1;
    int nextTerm = 0;
    
    while ( nextTerm <= limit)
    {
        if ( nextTerm % 2 == 0 )
            sum += nextTerm;
        
        nextTerm = firstTerm + secondTerm;
        
        firstTerm = secondTerm;
        secondTerm = nextTerm;       
    }
    
    return sum;
}
