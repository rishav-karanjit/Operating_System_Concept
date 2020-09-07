#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS_MEMORY_SIZE  10000

int FIFO=0, LRU=1, LFU=2; //wait-> to store the time of entering
int numProcess, frameSize;
int memory[100], wait[100]={0}, frameMemory[100]={0}
int frequency[MAX_PROCESS_MEMORY_SIZE]={0};

int findMaximum()   // to find the page which is arrived first by finding the maximum time waited by each process
{
    int max = 0, i;
    for(i=0; i<frameSize; i++)
        if(wait[i]>wait[max])
            max=i;
    return max;
}

int checkValueIndex(int ele)    //to get the index of the page in a frame_array
{
    int i;
    for(i=0; i<frameSize; i++)
        if(frameMemory[i] == ele)
            return i;
    return -1;
}

int findMinimumFrequency()  // to check the minimum frequency page which is arrived first
{
    int min = 0, i;
    frequency[min] = 9999;
    for(i=1; i<MAX_PROCESS_MEMORY_SIZE; i++)
    {
        if(frequency[i]<=frequency[min] && frequency[i]>0)
        {
            if(frequency[min] == frequency[i])
            {
                if(wait[checkValueIndex(min)] < wait[checkValueIndex(i)])
                    min = i;
            }
            else min = i;
        }
    }
    return min;
}

int checkPresent(int ind)   // to check whether the page is already present in frame array or not
{
    int i;
    for(i=0; i<frameSize; i++)
        if(frameMemory[i] == memory[ind])
        return i;
    return -1;
}

void display()  // to display frame contents
{
    int i;
    for(i=0; i<frameSize; i++)
        printf("%d\t", frameMemory[i]);
    printf("\n");
}

void resetMemory()  // to reinitialize all the elements to zero
{
    int i;
    for(i=0; i<frameSize; i++)
        frameMemory[i] = wait[i]=0;
}

void pageReplacement(int method)   //method indicates which algorithm to apply(as declared at the start of the program)
{
    int i, j, frameRepeat=0;
    for(i = 0; i < numProcess; i++)
    {
        int frameInd = checkPresent(i);
        if(frameInd >= 0)//for the repeated pages in the frame array
        {
            frameRepeat++;
            if(method==FIFO) wait[frameInd]++;
            if(method==LRU)  wait[frameInd]=0;
            if(method==LFU) frequency[memory[i]]++;
            for(j=0;j<frameSize ;j++)
                wait[j]++;
        }

        else if(i<(frameSize+frameRepeat))  //for the initial frame_size pages
        {
            frameMemory[i-frameRepeat] = memory[i];
            for(j=0;j<=(i-frameRepeat);j++)
                wait[j]++;
            if(method==LFU)
                frequency[memory[i]]=1;
        }

        else    // for the pages which are not present in frame_array
        {
            if(method==FIFO || method==LRU)
            {
                int ind = findMaximum();    // to get the page which is arrived first
                wait[ind]=0;    // initializing its time of arrival to zero
                frameMemory[ind] = memory[i];   // adding it to the frame_array
            }

            else if(method==LFU)
            {
                int ind = checkValueIndex(findMinimumFrequency());   // get the index of the frame_array which is arrived first and have minimum frequency
                wait[ind]=0;    // initializing its time of arrival to zero
                frameMemory[ind] = memory[i];   // adding it to the frame_array

                frequency[frameMemory[ind]]=0;  // initializing  the older(replaced) page frequency to zero
                frequency[memory[i]]=1;     // initializing  the newer page frequency to one
            }

            for(j=0;j<frameSize ;j++)
                wait[j]++;  //incrementing time for all the existing pages
        }
        display();
    }
}

int main()
{
    int i;
    printf("Enter the frame size and number process requires memory:");
    scanf("%d%d", &frameSize, &numProcess);
    printf("Enter the memory required by each process:");
    for(i=0;i<numProcess;i++)
        scanf("%d", &memory[i]);

    printf("FIFO:\n=====\n");
    pageReplacement(FIFO);
    resetMemory();//to set all elements to zero

    printf("\n\nLRU:\n=====\n");
    pageReplacement(LRU);
    resetMemory();//to set all elements to zero
    
    printf("\n\nLFU:\n=====\n");
    pageReplacement(LFU);
}
