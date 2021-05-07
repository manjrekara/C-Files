// Atharva Manjrekar
// ECE 1101 - HW5
// Dr. Chandy

#include "Matrix.h"
#include <stdio.h>

Matrix::Matrix(int m, char *filename):size(m)
{
    data = new double [size*size];
    double value;
    FILE *file = fopen(filename, "r"); //We open the file outside a for loop

    for(int i=0; i<m; i++) //loop to iterate over rows
    {
        for(int j=0; j<m; j++) //loop to iterate over columns
        {            
            fscanf(file, "%lf ", &value); //We scan Matrix data by rows and colums 
            data[i*m+j] = value; //data[i*m+j] gives us element at row i and column j
            printf("Matrix Data: %f \n", value);//Prints both matrix data every new line
        }
    }
}

Matrix::Matrix(int m)
: size(m){
    data = new double [size*size];
}

Matrix::Matrix(const Matrix &original)
: size(original.size){
    data = new double [size*size];
    double value = 0;
// Iterate through the original data and copy the values 
// into the new object data
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            data[i*size+j] = original.data[i*size+j];
        }
    }
}

Matrix::~Matrix(){
    delete [] data;
}

Matrix Matrix::operator * (Matrix &b) const{
    Matrix out(size);
    double sum = 0;

    for(int i=0; i<size; i++) //row loop
    {
        for(int j=0; j<size; j++) //column loop
        {
            for(int k=0; k<size; k++) //inner-most loop
            {
                sum += data[i*size+k] * b.data[j+size*k]; //multiply Matrix A by rows to Matrix B by columns
                printf("Matrix A: %2f \n", data[i*size+k]); //prints out Matrix A by rows
                printf("Matrix B: %2f \n", b.data[j+size*k]); //prints out Matrix B by columns
            }
            out.data[i*size+j] = sum; //accumulated sum goes to out.data at element i and j
            sum = 0; //reset sum
        }   
    }
    return out;
}

void Matrix::write(char *filename){
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                //iterate over both rows and colums of data
                fprintf(file, "%2f ", data[i*size+j]); //this will print our Matrix C output
            }
            fprintf(file, "\n"); //this prints a newline at the end of each row
    }
}