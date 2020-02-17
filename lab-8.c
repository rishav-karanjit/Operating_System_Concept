#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void main()
{
	char str[MAX];
	int i;
	
	printf("Enter the Identifier : ");
	gets(str);
	
	if( !isalpha(str[0])  && str[0] != '_' )
	{
		printf("\n --Invalid Identifier-- \n");
		return;
	}
	
	for( i=1; str[i] != '\0'; i++ )
	{
		if( !isalnum(str[i]) && str[i] != '_' )
		{
			printf("\n --Invalid Identifier-- \n");
			return;
		}
			
	}
	
	printf("\n --Valid Identifier-- \n");
}
