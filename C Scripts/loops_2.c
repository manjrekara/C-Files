#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        unsigned int result = n*factorial(n-1);
        return result;
    }
}

float power (float a, float b)
{
    float temp;
    if(b==0)
    {
        return 1;
    }
    else
    {
        temp = a*power(a,b-1); // solve for a^(b)
    }
    return temp;
}

// x represents the x in our equation while iteration represents the amount of terms we choose
float exponential (float x, float iteration) 
{
    float sum = 1;

    for(int i=1; i<=iteration; i++) // 0 to however many terms we choose
    {
        sum = sum + (power(x, i) / factorial(i)); 

    }
    return sum;
}

int main(int argc, char **argv)
{
    double val = atof(argv[1]);
    double val2 = atof(argv[2]);
    printf("exp(%1.5f) = %1.5f\n", val, exponential(val, val2));
    return 0;
}
