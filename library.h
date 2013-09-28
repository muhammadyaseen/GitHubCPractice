// PRE PROCESSOR DIRECTIVES
#define TRUE 0

// START FUNCTION PROTOTYEOPES

int evenFibonnaciTermsSum(int);
int largestPalindromeProduct(void);
int primesSum(int);
int amicableNumbers(void);
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

/* @descripton - Calculates largest palindrome product formed from two three-digit numbers
 * 
 * @returns - largest palindrome product
 * 
 * @note - Palindromes read the same, either ways e.g. 9009, 7007, 666,
 */

int largestPalindromeProduct()
{   
    int largestPalindrome = 0;

    for( int i = 100; i <= 999; i++)
    {
        for(int j = 100; j <= 999; j++)
        {
            int product = i*j;
            
            if ( isPalindrome(product) == TRUE && product > largestPalindrome)
            {
                largestPalindrome = product;
            }
        }
    }

    return largestPalindrome;  
}

/* @descripton - Decides whether the given number is a palindrome or not. It is used in largestPalindromeProduct() function as helper function
 *             - strcpy vs strdup : http://stackoverflow.com/questions/14020380/strcpy-vs-strdup
 * @param number - number to check
 * 
 * @returns - 0 or any value greater than 0 or less than zero, just as strcmp() does
 * 
 * @note - we only reserve 6 bytes for the string because a maximum of 6 digit palindrome is possible
 */

int isPalindrome(int number)
{
    char * testString = (char *)malloc( 6 * sizeof(char)); //a maximum of 6 digit palindrome is possible
    
    itoa(number, testString, 10);
    
    // we have to duplicate string because strrev() reverses the string in-place, in this way we loose our testString
    // hence to compare testString with reversed string we need a non-reversed string
    char * original = (char *)strdup(testString);
    
    strrev(testString);

    int result = strcmp( original, testString );
        
    free(original);
    free(testString);
    
    return result;
}

/* @descripton - Calculates the sum of prime numbers occuring in the given range, [0,range).
 * 
 * @param range - Upper range, exculsive
 * 
 * @returns - Sum of prime numbers terms.
 * @note - int might not be suitable for lager range
 */

int primesSum(int range)
{
    int sum = 0;
    
    for(int i = 0; i < range; i++)
    {
        if( isPrime(i) == TRUE)
            sum += i;
    }
    
    return sum;
}

/* @descripton - Solves project Euler problem # 27 http://projecteuler.net/problem=21
 * 
 * @returns - sum of amicable numbers with in given range
 * 
 * @note - the given range was 10,000. See link for details
 */

int amicableNumbers()
{
    int sumOfAmicables = 0;
    
    for (int i = 1; i <= 10000; i++)
    {
        int sumOfDivisorsA = 0;
        
        for(int divisor = 1; divisor <= i/2; divisor++)
        {
            if (i % divisor == 0)
                sumOfDivisorsA += divisor;
        }
        
        int b = sumOfDivisorsA;
        
        int sumOfDivisorsB = 0;
        
        for(int divisor = 1; divisor <= b/2; divisor++)
        {
            if ( b % divisor == 0 )
                sumOfDivisorsB += divisor;
        }

        if ( i == sumOfDivisorsB && b == sumOfDivisorsA && i != b)
        {
            sumOfAmicables += ( i );
        }
    }
    
    return sumOfAmicables;
}

/* @descripton - decides whether the given number is prime or not.
 * 
 * @param number - number to check
 * 
 * @returns - -1 or TRUE indicating the result of test
 */

int isPrime(int number)
{
    int limit = (int)floor(sqrt(number));
    
    for( int i = 2; i <= limit; i++)
    {
        if ( number % i == 0)
            return -1;
    }
    
    return TRUE;
}