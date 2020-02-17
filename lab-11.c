#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int numofproduct,k= 0  ; 
char productionset[10][10],str[20];
void recursiveDescent(char p)
{
	int found = 0 , temp , i , j  ; 
	for(i =0 ;i < numofproduct ; i++ )
	{
		if(productionset[i][0]==p){
			temp = k ; 
			int j;
			for( j =2 ; productionset[i][j] ; j++){
				if(str[k]=='#')k++ ; 
				if(isupper(productionset[i][j])){
					found = 1;
					recursiveDescent(productionset[i][j]) ; 
				}
				else if(productionset[i][j] == str[k]){
					k++ ; 
					found = 1 ;
				}
				else if (productionset[i][j] == '#'){
					found = 1 ; 
					break ; 
				}
				else{
					k = temp ; 
					break; 
				}
			}
		}
	}
	if((i>=numofproduct) && (found ==0) &&(k!=strlen(str)))
	{
		printf("\n invalid input:");
		exit(0);
	}
}
int main(void)
{
	printf("Number of productions:");
	scanf("%d",&numofproduct);
	printf("Enter the productions in the form E=T+E, enter # for epsilon : \n");
	int i;
	for( i=0;i<numofproduct;i++)
		scanf("%s",productionset[i]);
	while(1){
		k = 0 ; 	
		printf("\nEnter the string : ");
		scanf("%s",str);
		recursiveDescent(productionset[0][0]);
		if(k==strlen(str))
			printf("\n Input string is valid");
		else
			printf("\n Invalid string !!!");
	}
}

