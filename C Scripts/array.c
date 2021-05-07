#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    double values[10];
    int i;
    double average = 0;
    double min, max;
    int numvalues = argc-1;

    if (numvalues > 10) 
    {
        printf("Too many values\n");
        exit(-1);
    }
    for (i=1; i<argc; i++) 
    {
        values[i-1] = atof(argv[i]);
    }

    double sum = 0;
    min = values[0]; // initialize to first value index in array
    max = values[0]; // initialize to first value index in array

    for(int i=0; i<numvalues; i++)
    {
        
    sum = sum + values[i];

        if ((values[i] < min)) // continuously checks if next value in the array is less than the current min value
        {
            min = values[i];   // update our min value

        }
        if ((values[i] > max)) // continuously checks if next value in the array is higher than the current max value
        {
            max = values[i];   // update our max value

        }
    }  
    average = sum/numvalues;   // divides the sum of all numbers in array by the amount of numbers in the array
    
     printf("Average is %f\n", average);
     printf("Minimum is %f\n", min);
     printf("Maximum is %f\n", max);
}
