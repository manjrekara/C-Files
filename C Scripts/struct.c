#include <stdio.h>
#include <stdlib.h>

// typedef struct
// {
//     char name[100];
//     float cost;
//     int quantity;
// } receiptEntry;

    
// int main(int argc, char **argv)
// {
//     char *filename = argv[1];

//     FILE *fp;

//     fp = fopen(filename, "r");
//     if (fp == NULL) {
//         printf("Error reading file %s\n", filename);
//         exit(-1);
//     }

//     int i=0;
//     receiptEntry *entries = malloc(100 * sizeof(receiptEntry));

//     while (fscanf(fp, "%s %f %d\n", entries[i].name, &entries[i].cost,
//                   &entries[i].quantity) != EOF) {
//         i++;
//     }

//     int num_entries = i;
    
//     for (i=0; i<num_entries; i++) {
//         printf("%s %d %f\n", entries[i].name, entries[i].quantity, entries[i].cost);
//     }

//     fclose(fp);
// }


struct mydata {
    int foo;
    int bar;
            };

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
    struct mydata *data_array = malloc(10*sizeof(struct mydata));
    int i = 0;

    while (fscanf(fp, "%d %d\n", &data_array[i].foo, &data_array[i].bar) != EOF) 
    {
        i++; //i gets populated
        num_rows += 1;
        if((num_rows % 10) == 0)
        {
            data_array = realloc(data_array, (num_rows + 10)*sizeof(struct mydata));
        }
    }

    //printf("Number of rows is: %d\n", num_rows);
    int num_entries = i;
    
    for (i=0; i<num_entries; i++) 
    {
        printf("%d %d\n", data_array[i].bar, data_array[i].foo);
    }
    fclose(fp);
}
