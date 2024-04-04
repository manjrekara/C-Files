#include <stdlib.h>
#include "Matrix.h"

int main(int argc, char **argv)
{
    int m = atoi(argv[1]);

    Matrix A(m, argv[2]);
    Matrix B(m, argv[3]);
    Matrix C = A * B;
    
    C.write(argv[4]);
}
