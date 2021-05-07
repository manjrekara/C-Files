// Atharva Manjrekar
// Dr. Chandy
// ECE1101: Homework 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    int func = atof(argv[1]); // function 1, 2, or 3
    double a = atof(argv[2]); // lower bound
    double b = atof(argv[3]); // upper bound
    double deltax = atof(argv[4]); // deltax

    double N = (b-a)/deltax; 
    double sum = 0; // initialize sum as 0 and then update it later as the arclen value based on parameters

    printf("N: %f \n", N); // prints value of N

    for (int i=0; i<=N-1; i++) // all iterations from i=0 to i=N-1
    {
        if(func == 1) // if function is x
        {
            // use summation eq when f(x) = x
            sum = sum + ((2*sqrt(2))*deltax) / 2;
        }
        else if(func == 2) // if function is e^(x)
        {
            // use summation eq when f(x) = e^(x)
            sum = sum + ((sqrt(1 + pow(exp((a+(i)*deltax)),2))) + (sqrt(1 + pow(exp((a+(i+1)*deltax)), 2)))) * (deltax/2);
        }
        else if(func == 3) // if function is sqrt(1-x^2)
        {
            // use summation eq when sqrt(1-x^2)
            double temp1 = pow((a+(i)*deltax), 2); 
            double temp2 = pow((a+(i+1)*deltax), 2);
            sum = sum + ((sqrt(-1/(temp1-1))) + (sqrt(-1/(temp2-1)))) * (deltax/2); 
        }
    }

    printf("arclen value = %f \n", sum); // print arclen value based on parameters provided

}
