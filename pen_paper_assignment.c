#include<stdio.h>
struct student
{
	int pen;
	int paper;
	int ques_paper;
	int task;
}s1,s2,s3;
main()
{
//Student-1
	s1.pen=1;
	s1.paper=0;
	s1.ques_paper=0;
	s1.task=0;
//Student-2	
	s2.pen=0;
	s2.paper=1;
	s2.ques_paper=0;
	s2.task=0;
//Student-3	
	s3.pen=0;
	s3.paper=0;
	s3.ques_paper=1;
	s3.task=0;
	
	while(s1.task==0||s2.task==0||s3.task==0)
	{
		int a,b;
		printf("\n\nPress the two integer values of corresponding items in ascending order of which teacher wants to keep on table");
		printf("\n 1 - PEN\n 2 - PAPER\n 3 - QUESTION PAPER");
		scanf("%d%d",&a,&b);
		
		if(a==1 && b==2)
		{
			if(s3.task==1)
			{
				printf("\nAlready this combination have been placed on table");
			}
			else
			{
				s3.task=1;
				printf("Student-3 has finished the assignment");
			}
		}
		else if(a==1 && b==3)
		{
			if(s2.task==1)
			{
				printf("\nAlready this combination have been placed on table");
			}
			else
			{
				s2.task=1;
				printf("Student-2 has finished the assignment");
			}
		}
		else if(a==2 && b==3)
		{
			if(s1.task==1)
			{
				printf("\nAlready this combination have been placed on table");
			}
			else
			{
				s1.task=1;
				printf("Student-1 has finished the assignment");
			}
		}
		else
		{
			printf("\nINVALID INPUT");
		}
	}
	printf("\n\nAll the students Have finished th Assignment");
}
