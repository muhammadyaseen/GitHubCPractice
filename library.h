// PRE PROCESSOR DIRECTIVES
#define TRUE 0
#define L 20

// START FUNCTION PROTOTYEOPES

int evenFibonnaciTermsSum(int);
int largestPalindromeProduct(void);
int primesSum(int);
int amicableNumbers(void);
int isPalindrome(int);
int isPrime(int);
unsigned long sumFactorialDigits(int);
unsigned long long sumTruncatablePrimes(void);
char* strdel(char*, int);
char* strReverse(char*, char*);
int matMult(void);
int matAdd(void);
void strncatt(char [], char [], int);


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

/* @descripton - Calculates the factorial and sums each of it's digits.
 * 
 * @param int - The number whose factorial you which to use.
 * @param limit - try to keep it under 20. Not sure of the behavior after that.
 * 
 * @returns unsigned long - Sum of the digits of the factorial.
 */

unsigned long sumFactorialDigits(int n)
{ 
    unsigned long long factorial = 1; 
    unsigned long sum = 0;
    
    //If input is negative
    if(n < 0)
    {
        printf("\nFactorial of a negative number is not possible, you muppet!\n");
        return 0;
    }
    
    else
        //Factorial Calculation
        while(n > 1)
        {
            factorial = factorial * n--;
        }
    
    printf("\nFactorial Result = %llu\n", factorial);
    
    //Adding each digit of the factorial
    while (factorial != 0)
    {
        sum += (factorial % 10);
        factorial /= 10;
    }
    
    return sum;
}

/* @descripton - Finds the truncatable primes up to 75000 and sums them up.
 * 
 * @param void - None what so ever. There are only eleven of them anyways.
 * 
 * @returns unsigned long long - Sum of the truncatable primes.
 * 
 * @notes - Example of Truncatable Primes: 
 * 
 * The number 3797. Being prime itself, it is possible to continuously remove 
 * digits from left to right, and remains prime at each stage: 3797, 797, 97, 
 * and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 */

unsigned long long sumTruncatablePrimes(void)
{
    unsigned int rem = 0;
    unsigned long truncatedNumber;
    unsigned long long sum = 0;
    
    for(unsigned long long i = 11; i < 750000; i++)
    {
        //Checks for prime number
        for(unsigned long j = 2; j < floor(sqrt(i)) + 1; j++)
        {
            rem = i%j;
            if(rem == 0)
                break;
        }
        
        //Enters if 'i' is prime and checks for truncating from the RIGHT
        if (rem != 0)
        {
            //Declaration for another variable so 'i' is not tampered with
            //Also removes the RIGHT most digit
            truncatedNumber = i / 10;
            
            //Moves on if the number has a 1 on the extreme right side
            if(truncatedNumber == 1) 
                continue;

            //Loop to modify and check whether the numbers are prime as well
            while (truncatedNumber != 0)
            {
                //Checks for prime number
                for(unsigned long j = 2; j < truncatedNumber; j++)
                {
                    rem = truncatedNumber % j;
                    if(rem == 0)
                    {
                        break;
                    }
                }
                
                //Enters if 'truncatedVariable' is NOT prime and breaks out of 
                //the loop
                if(rem == 0)
                        break;
                
                //Removes one number from the RIGHT of the number
                
                truncatedNumber /= 10;
                
                //Breaks the loop if the number has a 1 on the extreme right side
                if(truncatedNumber == 1) 
                    break;
                
                //Does everything all over again until truncatedNumber == 0
            }
        }//End of truncations from the RIGHT
        
        
        //Enters if truncations from the right are primes and 
        //checks for truncating from the LEFT
        if(rem != 0 && truncatedNumber != 1)
        {   
            //Calculating the divider for i
            unsigned long divider = 1;
            
            while(i % divider != i)
                divider *= 10;
            
            divider /= 10;
            
            //First truncation from the LEFT
            truncatedNumber = i % divider;
            
            //Moves on if the number has a 1 on the extreme right side
            if(truncatedNumber == 1) 
                continue;
            
            //Breaks the loop if the number has a 1 on the extreme left side
            if(truncatedNumber == 1) 
                break;
            
            //Loop to modify and check whether the numbers are prime as well
            while (truncatedNumber != 0)
            {
                //Checks for prime number
                for(unsigned long j = 2; j < truncatedNumber; j++)
                {
                    rem = truncatedNumber % j;
                    if(rem == 0)
                        break;
                }
                
                //Enters if 'truncatedVariable' is NOT prime and breaks out of 
                //the loop
                if(rem == 0)
                        break;
                
                //Adjsuts the divider to truncate one less from the LEFT
                divider /= 10;
                
                //Removes one number from the LEFT of the number
                truncatedNumber = truncatedNumber % divider;
                
                //Breaks the loop if the number has a 1 on the extreme right side
                if(truncatedNumber == 1) 
                    break;
                
                //Does everything all over again until truncatedNumber == 0
                //or rem == 0, that is truncatedNumber is not a prime
            }
            
        }//End of truncations from the LEFT
      
        if(rem != 0 && truncatedNumber != 1)
        {
            sum += i;
        }      
    }
    
    return sum;    
}

/* @descripton - Deletes the character at the given index.
 * 
 * @param char* - The string to be modified
 * @param int - The index of the character you wish to remove.
 * 
 * @returns - Address of the string if you wish to use it in printf.
 * 
 * @note - I've set up some basic error checking but be careful not to pass in
 *         a string with no null character in the end.
 */


char* strdel(char *str, int pos)
{
    if(pos > strlen(str) || pos < 0)
    {
        printf("\nThe index does not exist.\n");
        return NULL;
    }
    
    int len = strlen(str);
    
    for(int i = pos; i < (len); i++)
        *(str+i) = *(str + i + 1);
    
    return str;
}

/* @descripton - Reverses a given string and stores it another string.
 * 
 * @param char *dest - The string to be modified
 * @param char *src - The string you wish to reverse.
 * 
 * @returns char* - Address of the reversed string if you wish to use it in 
 *                  printf.
 * 
 * @note - You'll need to give it a destination pointer, so declare a char
 *         pointer with sufficient memory using malloc().
 */

char* strReverse(char *dest, char *src)
{
    int len = strlen(src);
    
    for (int i = (len - 1), j = 0; i > -1; i--, j++)
        *(dest + j) = *(src + i);
    
    *(dest + len) = '\0';
    
    return dest;
}


int matMult(void){
	int a[10][10],b[10][10],c[10][10],n=0,m=0,i=0,j=0,p=0,q=0,k=0;
	int *pt,*pt1,*pt2;
	printf("Enter size of 1st 2d array : ");
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter element no. %d %d :",i,j);
			scanf("%d",&a[i][j]);

		}
	}
	printf("Enter size of 2nd 2d array : ");
	scanf("%d %d",&p,&q);
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("Enter element no. %d %d :",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	if(m!=p)
	{
		printf("Multiplication cannot be done\n");
		exit (0);
	}
	pt=&a[0][0];
	pt1=&b[0][0];
	pt2=&c[0][0];
	for(i=0;i<n;i++)
	{
		for(k=0;k<q;k++)
		{
			*(pt2+(i*10+k))=0;
			for(j=0;j<m;j++)
			{
				*(pt2+(i*10+k))+=*(pt+(i*10+j))**(pt1+(j*10+k));
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d	",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}



int matAdd() {
    int r, c, i, j;
    
    int a[200][200],b[200][200];
    printf("Enter the matrix: ");
    scanf("%d %d",&r,&c);
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter element no: [%d] [%d]: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter element no: [%d] [%d]: ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
            printf("%d\t",a[i][j]+b[i][j]);  
    }
    return 0;
}
/* @descripton - Concatenates n characters of a given string (src) to another string (dest)
 * 
 * @param char dest - The string to be modified
 * @param char src - The string you wish to add in dest. 
 * @returns void - Returns nothing.
 *
 */

void strncatt(char dest[], char src[], int n ) {
    int i, j=0;
    i=strlen(dest);
    
    while(j!=n) {
        dest[i++]=src[j++];
    }
        
    dest[i]='\0';
    
    printf( "\nConcatenated : ");
    puts(dest);
    
>>>>>>> 6ef280077051cd3382da2f291d4355ad467058b4
}