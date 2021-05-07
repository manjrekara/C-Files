#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {EE, CMPE, CSE, BME} major_type;

struct student 
{
    char *name;
    major_type major;
};
char *majors[] =  {"Electrical Engineering", "Computer Engineering", "Computer Science and Engineering", "Biomedical Engineering"};

void print_student(struct student* sp) 
{
    printf("%s - %s \n", sp->name, majors[sp->major]);
}

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
    int num_students = 0;
    char str[11];
    int major;
    struct student *memarray = calloc(10, sizeof(struct student));
    int i=0;

    while (fscanf(fp, "%10s %d\n", str, &major) != EOF) 
    {
        struct student *sp = &memarray[num_students];
        sp->name = strdup(str);
        if (major==0) sp->major = EE;
        else if (major==1) sp->major = CMPE;
        else if (major==2) sp->major = CSE;
        else if (major==3) sp->major = BME;
        num_students++;

        if ((num_students % 10) == 0) 
        {
            memarray = realloc(memarray, (num_students + 10)*sizeof(struct student));
        }
    }

    printf("\nNumber of students: %d\n\n", num_students);
    for(i=0; i<num_students; i++)
    {
        print_student(&memarray[i]);
    }

}
