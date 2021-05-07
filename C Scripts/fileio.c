#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char **argv)
// {
//     char *filename = argv[1];

//     FILE *fp;

//     fp = fopen(filename, "r");
//     if (fp == NULL) {
//         printf("Error reading file %s\n", filename);
//         exit(-1);
//     }

//     char name[100];
//     float cost;
//     int quantity;

//     while (fscanf(fp, "%s %f %d\n", name, &cost, &quantity) != EOF) {
//         printf("%s %d %f\n", name, quantity, cost);
//     }

//     fclose(fp);
// }

int main(int argc, char **argv)
{
    if (argc != 2 ) 
    {
        printf("%s filename\n", argv[0]);
        exit(0);
    }
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) 
    {
        perror("Could not open file");
        exit(0);
    }

    int num_rows = 0;
    int *column1 = malloc(10 * sizeof(int));
    int *column2 = malloc(10 * sizeof(int));

    int i,j;
    int data1, data2;

    while (1)
    {
        int retval = fscanf(fp, "%d %d\n", &data1, &data2);
        if (retval==EOF){
            break;
        } 
        //printf("this is data1: ", %d\n, data1);
        //printf("this is data2: ", %d\n, data2);
        column1[num_rows] = data1;
        column2[num_rows] = data2;

        num_rows += 1; //increasing the count of num_rows by 1 for every row

        if((num_rows % 10) == 0)
        {
            column1 = realloc(column1, (num_rows + 10)*sizeof(int));
            column2 = realloc(column2, (num_rows + 10)*sizeof(int));
        }
    }

    printf("Number of rows is %d\n", num_rows);

    for (i=0; i<num_rows; i++) 
    {
        printf("%d ", column2[i]);
        printf("%d\n", column1[i]);
    }
}




