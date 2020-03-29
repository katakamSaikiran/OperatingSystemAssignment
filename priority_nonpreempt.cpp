/*
Two types of people can enter into a library- students and teachers. After entering the library, the 

visitor searches for the required books and gets them. In order to get them issued, he goes to the single 

CPU which is there to process the issuing of books. Two types of queues are there at the counter-one 

for students and one for teachers. A student goes and stands at the tail of the queue for students and 

similarly the teacher goes and stands at the tail of the queue for teachers (FIFO). If a student is being 

serviced and a teacher arrives at the counter, he would be the next person to get service (PRIORITY￾non preemptive). If two teachers arrive at the same time, they will stand in their queue to get service 

(FIFO). WAP to ensure that the system works in a non-chaotic manner.
*/
#include<stdio.h>
using namespace std;
#include<iostream>
#include<bits/stdc++.h>
struct process 
{  int processId;	
	int arrivalTime;
	int cpuBurstTime; 
	int queueNumber;     //1 for teacher queue 2 for student queue 
	bool isTaskDone;      //1 for completion 0 for noncompletion 	
	int taskCompletedTime;	
};
void sort(struct process p[20],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			if(p[j].arrivalTime>p[j+1].arrivalTime)
			{
				int temp=p[j].arrivalTime;
				p[j].arrivalTime=p[j+1].arrivalTime;
				p[j+1].arrivalTime=temp;

				temp=p[j].cpuBurstTime;
				p[j].cpuBurstTime=p[j+1].cpuBurstTime;
				p[j+1].cpuBurstTime=temp;

				temp=p[j].queueNumber;
				p[j].queueNumber=p[j+1].queueNumber;
				p[j+1].queueNumber=temp;

				temp=p[j].taskCompletedTime;
				p[j].taskCompletedTime=p[j+1].taskCompletedTime;
				p[j+1].taskCompletedTime=temp;


				temp=p[j].processId;
				p[j].processId=p[j+1].processId;
				p[j+1].processId=temp;

			}
		}
	}
}
int main()
{
	struct process p[20];
	int n;
	printf("No of processes to Enter\n");
	scanf("%d",&n);
	int arrivalTime;
	int cpuBurstTime;
	int queueNumber;
	for(int i=0;i<n;i++)
	{
		printf("Enter Details of process %d\n",i+1);
		printf("processId\n");
		scanf("%d",&p[i].processId);
		printf("ArrivalTime\n");
		scanf("%d",&p[i].arrivalTime);
		printf("cpuBurstTime\n");
		scanf("%d",&p[i].cpuBurstTime);
		printf("QueueNumber\n");
		printf("Enter 1 for Teacher 2 for Student\n");
		scanf("%d",&p[i].queueNumber);
		printf("\n");
		p[i].isTaskDone=false;
		p[i].taskCompletedTime=0;
	}

	sort(p,n);

	for(int i=0;i<n;i++)
	{
		printf("%d %d %d\n",p[i].arrivalTime,p[i].cpuBurstTime,p[i].queueNumber);
	}
	//int count=0;
	int currentCpuTime=p[0].arrivalTime;
	while(1)
	{
		int f=0;
		for(int i=0;i<n;i++)
		{
			if(p[i].isTaskDone==false)
			{
				if(p[i].arrivalTime<=currentCpuTime)
				{
					if(p[i].queueNumber==1)
					{
						f=1;
						p[i].isTaskDone=true;
						p[i].taskCompletedTime=currentCpuTime+p[i].cpuBurstTime;
						currentCpuTime=currentCpuTime+p[i].cpuBurstTime;
						printf("Execution of process %d is completed\n",p[i].processId);
						printf("waitingTime of this Process %d\n",(p[i].taskCompletedTime-p[i].arrivalTime-p[i].cpuBurstTime));
						break;
					}
				}
			}
		}
		if(f==0)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].isTaskDone==false)
				{
					p[i].isTaskDone=true;
					p[i].taskCompletedTime=currentCpuTime+p[i].cpuBurstTime;
					currentCpuTime=currentCpuTime+p[i].cpuBurstTime;
					printf("Execution of process %d is completed\n",p[i].processId);
                                                printf("waitingTime of this Process %d\n",(p[i].taskCompletedTime-p[i].arrivalTime-p[i].cpuBurstTime));

					break;
				}
			}

		}
		int isAllComplete=1;
		for(int i=0;i<n;i++)
		{
			if(p[i].isTaskDone==false)
			{
				isAllComplete=0;
				break;
			}
		}
		if(isAllComplete==1)
		{
			printf("All Processes CPU Execution Completed!!!!\n");
			break;
		}

	}








}
