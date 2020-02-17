#include<stdio.h>
#include<ctype.h>

void FIRST(char c, int q1, int q2);

int count,n=0;
char prodn[10][10], first[10];

void main()
{
	int i,choice;
	char c,ch;
	printf("How many prodns ? :");
	scanf("%d",&count);
	printf("Enter %d prodns epsilon= # :\n\n",count);
	for(i=0;i<count;i++)
		scanf("%s%c",prodn[i],&ch);
	do
	{
		n=0;
		printf("Element :");
		scanf("%c",&c);
		FIRST(c,0,0);
		printf("\n FIRST(%c)= { ",c);
		for(i=0;i<n;i++)
			printf("%c ",first[i]);
		printf("}\n");
		printf("press 1 to continue : ");
		scanf("%d%c",&choice,&ch);
	}
	while(choice==1);
}

void FIRST(char c, int q1, int q2)
{
	int j;       
    // The case where we  
    // encounter a Terminal 
    if(!(isupper(c)))
        first[n++] = c; 
    for(j = 0; j < count; j++) 
    { 
		if(prodn[j][0] == c) 
        { 
			if(prodn[j][2] == '#') 
            { 
				if(prodn[q1][q2] == '\0')
				{
                    //first[n++] = '#'; 
                    printf("\nElement not found");
                    first[n++]=' ';
				}
                else if(prodn[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) 
                { 
                    // Recursion to calculate First of New 
                    // Non-Terminal we encounter after epsilon 
                    FIRST(prodn[q1][q2], q1, (q2+1)); 
                } 
                else
                    first[n++] = '#'; 
			}
			 
			else if(!isupper(prodn[j][2])) 
            { 
                first[n++] = prodn[j][2]; 
            } 
            
            else 
            { 
                // Recursion to calculate First of New Non-Terminal we encounter at the beginning 
                FIRST(prodn[j][2], j, 3); 
            } 
        } 
    }
}
