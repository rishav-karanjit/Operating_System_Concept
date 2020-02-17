#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void closure(char []);
char citem[10][10],gram[10][10];
int nop,noi;
int main()
{
    int choice,i;
    char agram[10][10],item[10];
    printf("\n how many number of productions:\n");
    scanf("%d",&nop);
    printf("\n Enter the productions like this eg: E->E+T Enter # for epsilon \n");
    for(i=0;i<nop;i++)
    {
        printf("\n Enter the production %d:",i+1);
        scanf("%s",gram[i]);
    }
    agram[0][0]=gram[0][0];
    agram[0][1]='!';
    agram[0][2]='-';
    agram[0][3]='>';
    agram[0][4]=gram[0][0];
    agram[0][5]='\0';
    
    for(i=1;i<=nop;i++)
    strcpy(agram[i],gram[i-1]);
    printf("\n Augmented grammer:");
    for(i=0;i<=nop;i++)
    printf("%s  ",agram[i]);
    
    do
    {
        printf("\n Enter the item to find the closure:");
        scanf("%s",item);
        printf("\n closure of %s = { ",item);
        closure(item);
        for(i=0;i<noi;i++)
        {
        printf(" %s ",citem[i]);
        }
        printf("}\n");
        
        printf("\n enter 1:to continue 2:to stop \n");
        scanf("%d",&choice);
    }
    while(choice==1);
    return 0;
    
}
void closure(char it[20])
{
    int i,j,l,k=0,found=0;
    char temp[10];
    noi=0;
    strcpy(citem[k],it);
    noi++;
    while(k<noi)
    {
	    i=0;
	    while(it[i]!='\0' && it[i]!='.')
		    i++;
	    if(i<(strlen(it)-1))
	    {
		    for(j=0;j<nop;j++)
		    {
			    found =0;
			    if((it[i+1]==gram[j][0]) && isupper(it[i+1]))
			    {
			    strcpy(temp,gram[j]);
			    for(l=strlen(temp);l>=3;l--)
				    temp[l+1]=temp[l];
				    temp[l+1]='.';
			    for(l=0;l<noi;l++)
				    if(strcmp(citem[l],temp)==0)
					    found=1;
			    if(found==0)
			    {
				    strcpy(citem[l],temp);
				    noi++;
			    }
		    }
	    }
    }
    else
    {
     	printf("%s}",it);
     	exit(0);
    }
    k++;
    strcpy(it,citem[k]);
    }return ;
    }

