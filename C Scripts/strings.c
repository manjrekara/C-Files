#include <stdio.h>

int main(int argc, char **argv)
{
    char *str = argv[1];

    int length;
    int i;

    

    for (i=0; str[i] != 0; i++) 
  	{
  		if(str[i] >= 'a' && str[i] <= 'z') // if there are any lowercase characters
      {
  			str[i] = str[i] - 32; // subtract 0x20 
		  }
  	}
    length = i;

    printf("The length of the string is: %d\n", length);
    printf("The capitalized string is: %s\n", str);
}
