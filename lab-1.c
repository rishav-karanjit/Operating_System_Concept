#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct process
{
	int arrival;
	int burst;
	int wait;
	int turn;
	int proc; //process number
};

void sort_arrival(struct process p[], int n);
void swap(struct process *p1, struct process *p2);

void main()
{
	struct process p[MAX];
	p[0].turn=0;
	p[0].burst=0;
	p[0].arrival=0;
	double total_wait=0, total_turn=0;
	int i, j, num;

	printf("\nEnter number of processes:");
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		p[i].proc = i;
		printf("\nProcess %d",i);
		printf("\n\tArrival time:");
		scanf("%d", &p[i].arrival);
		printf("\tBurst time  :");
		scanf("%d", &p[i].burst);
	}

	sort_arrival(p,num);

	for(i=1;i<=num;i++)
	{
		if(p[i].arrival <= p[i-1].turn)
		{
			p[i].turn = p[i-1].turn + p[i-1].arrival + p[i].burst - p[i].arrival ;
			p[i].wait = p[i-1].turn + p[i-1].arrival - p[i].arrival;
		}
		else
		{
			p[i].turn = p[i].burst;
			p[i].wait = 0;
		}
	}

	for(i=1; i<=num; i++)
	{
		printf("\nWaiting time of process%d = %d", i, p[p[i].proc].wait );
		total_wait += p[i].wait;
	}

	printf("\nAverage waiting time = %lf ms\n",total_wait/num );

	for(i=1;i<=num;i++)
	{
		printf("\nTurn around time of process%d = %d", i, p[p[i].proc].turn );
		total_turn += p[i].turn;
	}

	printf("\nAverage turn around time = %lf ms\n", total_turn/num );
}

void sort_arrival(struct process p[], int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for(j = 1; j <= n-i; j++)
        {
        	if (p[j].arrival > p[j+1].arrival)
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
