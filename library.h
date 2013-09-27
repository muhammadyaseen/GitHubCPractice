// PRE PROCESSOR DIRECTIVES


// START FUNCTION PROTOTYEOPES

void printName(char*);
void doSomething(char *);
int boringForLoop(int);
int sumPlease(int,int);
float add(float, float);

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

void printName(char* name)
{
    printf("\nThe given name is %s.\n", name);
}

void doSomething(char *task)
{
    puts(task);
}

int boringForLoop(int limit)
{
    for(int i = 0; i < limit; i++)
    {
        // I waste time
    }
}

int sumPlease(int a, int b)
{
    return a + b;
}


float add(float x, float y)
{
    return (x+y);
}

