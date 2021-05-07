#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

typedef enum {EE, CMPE, CSE, BME} major_type;
const char *majors[] =  {"Electrical Engineering", "Computer Engineering", "Computer Science and Engineering", "Biomedical Engineering"};

class Student 
{
    public:
        Student(const char *, major_type);
        string name;
        major_type majorr; 
        void print_student();
};

Student::Student(const char *a, major_type b)
    : name(a), majorr(b)
{
}

void Student::print_student() {
    cout << name << " -++- " << " " << majorr[majors] << endl;
    //cout << name << " + " << " " << majors[majorr] << endl;
}

int main(int argc, char **argv)
{
    if (argc != 2 ) {
        printf("%s filename\n", argv[0]);
        exit(0);
    }
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Could not open file");
        exit(0);
    }

    int num_students = 0;
    char str[11];
    int major;
    Student *Students = (Student *)calloc(10, sizeof(Student));

     while (fscanf(fp, "%10s %d\n", str, &major) != EOF) 
     {
        Student *sp = &Students[num_students];
        sp->name = str;
        if (major==0) sp->majorr = EE;
        else if (major==1) sp->majorr = CMPE;
        else if (major==2) sp->majorr = CSE;
        else if (major==3) sp->majorr = BME;
        num_students++;
        if ((num_students % 10) == 0) 
        { 
            Students = (Student *)realloc(Students, (num_students + 10)*sizeof(Student));
        }
     }
    
    printf("\nNumber of students: %d\n\n", num_students);
    
    for (int i=0; i<num_students; i++) 
    {
        Students[i].print_student();
    }
}
