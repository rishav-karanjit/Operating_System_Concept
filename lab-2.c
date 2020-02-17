# include<stdio.h>
# include<stdlib.h>
# define MAX 10

struct process
{
	int arrival;
	int burst;
	int wait;
	int turn; //turnaround time
	int proc;
	int priority;
	int rem; //remaining time
};

void sort_priority(struct process p[], int n);
void sort_proc(struct process p[], int n);
void swap(struct process *p1, struct process *p2);

void main()
{
	struct process p[MAX];
	double total_wait=0, total_turn=0;
	int i, j, k, num;
	
	printf("\nEnter number of processes:");
	scanf("%d", &num);
	
	for(i=0; i<num;i++)
	{
		printf("\nProcess %d",i+1);
		printf("\n\tArrival time:");
		scanf("%d", &p[i].arrival);
		printf("\tBurst time  :");
		scanf("%d", &p[i].burst);
		printf("\tPriority    :");
		scanf("%d",&p[i].priority);
		p[i].proc = i+1;
		p[i].wait=0;
		p[i].rem = p[i].burst; //initialising remaining time with burst time
	}
	
	sort_priority(p, num);
	
	for(i=0,k=0; k<num; i++) //i counter counts the seconds passed
	//each iteration means one second time 
	{						 
		for(j=0; j<num; j++) 
		{
			if(p[j].arrival <= i && p[j].rem != 0)
			{
				p[j].rem--; 
				if(p[j].rem == 0)
				{
					k++;
					p[j].wait = i+1 - (p[j].burst + p[j].arrival);
					p[j].turn = p[j].wait + p[j].burst;
				}	
				break;
			}
		}
	}
	
	sort_proc(p, num);
	
	for(i=0;i<num;i++)
	{
		printf("\nWaiting time of process%d = %d", i+1, p[i].wait );
		total_wait += p[i].wait;
	}
	
	printf("\nAverage waiting time = %lf ms\n",total_wait/num );
	
	for(i=0;i<num;i++)
	{
		printf("\nTurn around time of process%d = %d", i+1, p[i].turn );
		total_turn += p[i].turn;
	}
	
	printf("\nAverage turn around time = %lf ms\n", total_turn/num );
}

void sort_priority(struct process p[], int n)
{ 
    int i, j;
    for (i = 0; i < n; i++) 
    {  
        for(j = 0; j < n-i-1; j++)
        {
        	if (p[j].priority > p[j+1].priority) 
        		swap(&p[j], &p[j+1]);
        }

    }
} 

void sort_proc(struct process p[], int n)
{ 
    int i, j;
    for (i = 0; i < n; i++) 
    {  
        for(j = 0; j < n-i-1; j++)
        {
        	if (p[j].proc > p[j+1].proc) 
        		swap(&p[j], &p[j+1]);
        }

    }
} 

void swap(struct process *p1, struct process *p2)
{
	struct process temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}	
