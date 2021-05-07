#include <stdio.h>


double average_variance(char* data, int N, double *sumptr)
{
    double sumAvg = 0; 
    double sumVar = 0;
    for(int i=0; i<N; i++)
    {
        sumAvg += data[i]; //calculates the sum of our array
        sumVar += (data[i]*data[i]); //calculates the sum of our array and squares it
    }
    double avg = sumAvg/N; //find average
    double variance = (sumVar/N) - (avg*avg); //find variance

    *sumptr = variance;
    return avg;
}

int main(int argc, char **argv)
{
    char values[] = {1,2,3,5,6,7};
    double variance;
    double average = average_variance(values,6,&variance);
    printf("average = %f variance = %f \n", average, variance);
}
