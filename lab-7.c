#include<stdio.h>
#include<stdlib.h>
#define MAX 30

void main()
{
	char str[MAX];
	char ch;
	int i, state = 0;
	
	printf("Enter the string : ");
	gets(str);
	
	for(i=0; str[i] != '\0'; i++)
	{
		ch = str[i];
		switch(state)
		{
			case 0: if(ch == 'a')			state=1;
					else if(ch == 'b') 		state=4;
					else 					state=6;
					break;
					 
			case 1: if(ch == 'a')			state=5;
					else if(ch == 'b')		state=2;
					else					state=6;
					break;
					
			case 2: if(ch == 'b')			state=3;
					else 					state=6;
					break;
					
			case 3: if(ch == 'b') 			state=4;
					else 					state=6;
					break;
					
			case 4: if(ch == 'b') 			state=4;
					 else 					state=6;
					 break;
					
			case 5: if(ch == 'a')			state=5;
					else if(ch == 'b') 		state=4;
					else 					state=6;
					break;
					
			case 6: printf("\n Invalid string \n");
					 return ;  
		}
	}
	
	if(state == 6)
		printf("\n Invalid String \n");
	
	else if(state == 0 || state == 1 || state == 5)
		printf("\nString accepted under a* \n");
		
	else if(state == 2 || state == 4)
		printf("\nString accepted under a*b+ \n");
		
	else 
		printf("\nString accepted under abb \n");
}
