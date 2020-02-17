#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void addtonont(char);
void addtoter(char);
int nop,ppt[10][10];
char productions[10][10],ter[10],nont[10],first[10][10],follow[10][10];
int main()
{
	int i,j,k,m,pos=0;
	for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	ppt[i][j]=-1;
	printf("How many number of productions:");
	scanf("%d",&nop);
	printf("\nEnter production like this eg:E->E+T Enter # for epsilon\n");
	for(i=0;i<nop;i++)
	{
		printf("Enter production number %d:",i+1);
		scanf("%s",productions[i]);
	}
	for(i=0;i<nop;i++)
	addtonont(productions[i][0]);
	for(i=0;i<nop;i++)
	for(j=3;productions[i][j]!='\0';j++)
	if(islower(productions[i][j])||(!isalpha(productions[i][j])))
	addtoter(productions[i][j]);
	for(j=0;ter[j]!='\0';j++);
	ter[j]='$';
	ter[++j]='\0';
	printf("Enter first of all non terminals without any space b/w the symbols like abc#,#for epsilon\n" );
	for(i=0;i<nop;i++)
	{
		printf("Enter first of:");
		for(k=3;k<productions[i][k]!='\0';k++)
		printf("%c",productions[i][k]);
		printf("=");
		scanf("%s",first[i]);
		for(j=strlen(first[i]);j>=0;j--)
		first[i][j+1]=first[i][j];
		first[i][0]=productions[i][0];
	}
	printf("Enter follow of all non terminals without any space b/w symbols like abc#, # for epsilon\n");
	for(i=0;nont[i]!='\0';i++)
	{
		printf("Enter follow of %c=",nont[i]);
		scanf("%s",follow[i]);
		for(j=strlen(follow[i]);j>=0;j--)
		follow[i][j+1]=follow[i][j];
		follow[i][0]=nont[i];
	}
	for(i=0;i<nop;i++)
	{
		for(m=0;follow[m][0]!=first[i][0];m++);
		for(j=1;first[i][j]!='\0';j++)
		if(first[i][j]!='#')
		{
			for(k=0;ter[k]!='\0';k++)
			if(ter[k]==first[i][j])
			break;
			ppt[m][k]=i;
		}
		else
		{
			for(m=0;follow[m][0]!=first[i][0];m++);
			for(j=1;follow[m][j]!='\0';j++)
			{
				for(k=0;ter[k]!='\0';k++)
				if(ter[k]==follow[m][j])
				break;
				ppt[m][k]=i;
			}
		}
		first[i][0]='0';
	}
	printf("Predictive parsing table\n");
	printf("..................Terminals.................\n");
	printf("Non Terminals |\t\t");
	for(i=0;ter[i]!='\0';i++)
	printf("%c\t",ter[i]);
	printf("\n");
	for(i=0;follow[i][0]!='\0';i++)
	{
		m=0;
		printf("%c\t\t",nont[i]);
		for(j=0;ter[j]!='\0';j++)
		{
			pos=ppt[i][j];
			for(;m<=j;m++)
			printf("\t");
			if(pos!=-1)
			printf("%s",productions[pos]);
		}
		printf("\n");
	}
	return 0;
}
void addtonont(char c)
{
	int j;
	for(j=0;nont[j]!='\0';j++)
	if(nont[j]==c)
	return ;
	nont[j]=c;
	nont[j+1]='\0';
}
void addtoter(char c)
{
	int j;
	for(j=0;ter[j]!='\0';j++)
	if(ter[j]==c)
	return ;
	if(c!='#')
	{
		ter[j]=c;
		ter[j+1]='\0';
	}
}
