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

unsigned int binomial(int n, int k)
{
    if(k>n)
    {
        printf("N should be greater than K \n");
        return 0;
    }
    else
    {    
        int a = factorial(n);
        int b = factorial(n-k);
        int c = factorial(k);
        int binom = (a/(b*c));
        return binom;
    }
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int f = binomial(n,k);
    printf("%d choose %d is %d \n", n, k, f);
    return 0;
}
