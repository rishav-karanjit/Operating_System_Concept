#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

int getNextProcess(int work[], int current);
bool findSafeSequence();

int N; // Processes
int R; // Resource types
int allocation[SIZE][SIZE];
int max[SIZE][SIZE];
int need[SIZE][SIZE];
int available[SIZE];
bool finish[SIZE];
int safeSequence[SIZE];

int main()
{
	int i, j;
	bool exist = false;

	printf("Enter number of processes : ");
    scanf("%d", &N);

    printf("Enter number of Resource types : ");
    scanf("%d", &R);

    printf("Enter Allocation matrix : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < R; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Max matrix : \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < R; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Enter Available array : \n");
    for (i = 0; i < R; i++)
    {
        scanf("%d", &available[i]);
	}

	exist = findSafeSequence();

	if(exist)
	{
		printf("Safe sequence is: ");
		for(i=0; i<N; i++)
			printf("P%d  ", safeSequence[i]);
	}

	else
		printf("\nSafe sequence doesn't exist \n");
}

bool findSafeSequence()
{
	int work[SIZE];
	int current = -1; //current process
	int i, j;
	int k = 0;	//safe sequence pointer

	/*step1*/
	for (i = 0; i < N; i++)
	{
		work[i] = available[i];
		finish[i] = false;
	}

	while(true)
	{
		/*step2*/
   		current = getNextProcess(work, current);

   		if(current != -1)	//a process exist whose need can be fulfilled
    	{
    		/*step3*/
    		for(j=0; j<R; j++)
    			work[j] += allocation[current][j];

    		finish[current] = true;
    		safeSequence[k++] = current;
    			continue;	//goto step 2
    	}

    	else	//no such process exist
    	{
   			/*step4*/
    		for(i=0; i<N; i++)
    		{
   				if(finish[i] == false)
    				return false; //safe sequence doesn't exist
   			}
   			return true;	//safe sequence exist
   		}
   	}
}


int getNextProcess(int work[], int current)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        current = (current+1)%N ;
        if(finish[current]) continue ;

        bool flag = true;
        for (j = 0; j < R; j++)
        {
            if (need[current][j] > work[j])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            continue;	//current process can't be satisfied

        return current;	//return the process to be fulfilled
    }
    return -1; //no such process
}


