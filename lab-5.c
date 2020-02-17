#include <stdio.h>
#include <stdlib.h>

int processMemory[100];
int tempMemory[100];
int memory[100];
int noMemoryBlock; // number of memory block
int noProcesses;   // number of processes

void fnFirstFit()
{
    int i, j;
    printf("\nFirstFit \nProcess\t\tMemoryBlock");
    for(i=0; i<noProcesses; i++)
    {
        int flag = 0;
        for(j=0; j<noMemoryBlock; j++)
		{
            if(processMemory[i] <= memory[j])
            {
                flag=1;
                memory[j] -= processMemory[i];
                printf("\n%d\t\t%d", i+1, j+1);
                break;
            }
		}
        if(flag==0)
            break;
    }
    if(i != noProcesses)
        printf("\nCan't allocate further");
}

void fnWorstFit()
{
    int i, j;
    printf("\nWorstFit \nProcess\t\tMemoryBlock");
    for(i=0; i<noProcesses; i++)
    {
        int high = -1;
        for(j=0; j<noMemoryBlock; j++)
        {
            if(processMemory[i] <= memory[j])
            {
                if(memory[high] <memory[j] || high == -1)
                    high = j;
            }
        }
        if(high != -1)
        {
            memory[high] -= processMemory[i];
            printf("\n%d\t\t%d",i+1,high+1);
        }
        else
        {
            printf("\nCant allocate further");
            return;
        }
    }
}

void fnBestFit()
{
    int i,j;
    printf("\nBestFit \nProcess\t\tMemoryBlock");
    for(i=0; i<noProcesses; i++)
    {
        int low = -1;
        for(j=0; j<noMemoryBlock; j++)
        {
            if(processMemory[i] <= memory[j])
            {
                if(memory[low]>memory[j] || low == -1)
                    low = j;
            }
        }
        if(low != -1)
        {
            memory[low]-=processMemory[i];
            printf("\n%d\t\t%d",i+1,low+1);
        }
        else
        {
            printf("\nCant allocate further");
            return;
        }
    }
}

void restore()
{
    int i;
    for(i=0; i<noMemoryBlock; i++)
    {
        memory[i] = tempMemory[i];
    }
}

int main()
{
    int i, choice;
    printf("\nEnter the total number of memory blocks: ");
    scanf("%d", &noMemoryBlock);

    printf("\nEnter the total number of requested processes: ");
    scanf("%d", &noProcesses);
    
    printf("\nEnter the size of memory blocks\n");
    for(i=0; i<noMemoryBlock; i++)
    {
        printf("Block %d = ",i+1);
        scanf("%d", &tempMemory[i]);
    }
    
    printf("\nEnter the size of memory requested by processes\n");
    for(i=0;i<noProcesses;i++)
    {
        printf("Process %d = ",i+1);
        scanf("%d",&processMemory[i]);
    }
        
    while(1)
    {
        printf("\nEnter 1. FirstFit, 2. BestFit, 3. WorstFit 4. Exit \nEnter your choice:");
        scanf("%d",&choice);
        restore();
        if(choice == 1)     fnFirstFit();
        else if(choice == 2)     fnBestFit();
        else if(choice == 3)     fnWorstFit();
        else exit(0);
    }
}