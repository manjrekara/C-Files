// Atharva Manjrekar
// ECE 1101 - HW3
// Dr. John Chandy

#include <stdio.h>
#include <stdlib.h>

int comp(char *a, char *b) //comparison function
{
    while( (*a != '\0' && *b != '\0' ) && *a == *b ) // loop for the whole string to iterate
    {
        a++;      
        b++;  
    }
    if(*a == *b) // if two strings are the same
    {
        return 0; // strings are identical...return a integer of value 0
    }
    else // if two strings are not the same
    {
        return 1; 
    }
}

char *cap(char string[]) //capitalization function
{
    for (int i = 0; string[i] != 0; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z') 
            {
                string[i] = string[i] - 32; //subtract by 0x20
            }
    }
    return string;
}

int main(int argc, char **argv)
{
    char input[100];
    int i,j;

    char *input_strings[] = { "HELLO\n", "WHAT IS YOUR NAME?\n", "HOW ARE YOU?\n" };    

    while (1) //infinite loop
    {
        printf("> ");  // get the input string
        fgets(input, 100, stdin);

        char *temp = cap(input); //capitalize the input and store it into a temp string
        
        if (comp(temp,"BYE\n") == 0) 
        {
            printf("See you later\n");
            break; //break while loop
        }
        else if(comp(temp, input_strings[0]) == 0)
        {
            printf("Hello\n");
        }
        else if(comp(temp, input_strings[1]) == 0)
        {
            printf("My name is Atharva Manjrekar\n");
        }
        else if(comp(temp, input_strings[2]) == 0)
        {
            printf("I am fine\n");
        }
        else
        {
            printf("I do not understand\n");
        }   
    }
}