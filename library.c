#include<stdio.h>
int main()
{
	//process-p, burst_time-bt, teacher_or_student-su, waiting_time-wt, turn_around_time-tat.
	int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp, n1, n2;
	float wtavg, tatavg;
	printf("\nEnter the number of PROCESSES  in the Teachers queue - ");
	scanf("%d",&n1);
	printf("\nEnter the number of PROCESSES  in the Students queue - ");
	scanf("%d",&n2);
	n=n1+n2;
	
	//Entering the processes
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("\nEnter the Burst Time for process[%d] - ", i);
		scanf("%d",&bt[i]);
		printf("\nEnter 0-->TEACHER or 1-->STUDENT for Process[%d] - ",i);
		scanf("%d", &su[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(su[i] > su[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=su[i];
				su[i]=su[k];
				su[k]=temp;
			}
		}
	}
	
	//calculating average waiting time and turn around time
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\nPROCESS\t\t TEACHER/STUDENT PROCESS  \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	//Complete table for given task
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t %d \t\t\t\t %d \t\t %d \t\t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
	}
	
	printf("\nOrder of processes that executes is  ");
	for(i=0;i<n;i++)
	{
		printf("P-%d, ",p[i]);
	}
	printf("\nAverage Waiting Time is --- %f",wtavg/n);
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);
	return 0;
}
