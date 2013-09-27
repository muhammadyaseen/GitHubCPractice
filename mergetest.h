/*
 * test file for merge conflicts
 */

void printName(char *);
float add(float, float);
void ruinName(char*);

void printName(char* name)
{
    printf("\nThe given name is %s.\n", name);
}

float add(float x, float y)
{
    return (x+y);
}

void RunLoo()
{
    for(int x=0; x < 100; x++)
    {
        //do nothing
    }
}

int isEven(int x)
{
    return x % 2 == 0;
}

void ruinName(char* name)
{
    name = "Ruined.";
}
