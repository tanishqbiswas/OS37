#include <stdio.h>

struct student
{
    int StudentId;
    int FTakenTime;
    int WaitingTime;
    int TurnAroundTime;
};

void input(struct student list[], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Student #%d", i + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &list[i].StudentId);

        printf("Enter time taken for Food (minuts): ");
        scanf("%d", &list[i].FTakenTime);
    } 
}
void display(struct student list[], int s)
{
    int i,AvgWaitingTime=0,AvgTurnAroundTime=0;
	int TotalWatingTime=0,TotalTurnAroundTime=0;
    printf("\n\n\t\t\tOutput according to LRTF\n");
    printf("\n\t\t\t|===============================================================|");
    printf("\n\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n\t\t\t|===============================================================|");    
    for (i = 0; i < s; i++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d    \t  ", list[i].StudentId, list[i].FTakenTime,list[i].WaitingTime,list[i].TurnAroundTime);
        printf("\a\n\t\t\t|---------------------------------------------------------------|");
		TotalWatingTime= TotalWatingTime+list[i].WaitingTime;
		TotalTurnAroundTime= TotalTurnAroundTime+list[i].TurnAroundTime;
	} 
	printf("\n\n\t\t\tTotal Waiting Time is: = %d",TotalWatingTime);
	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",TotalTurnAroundTime);
	printf("\n\n\t\t\tAverage Waiting Time is: = %d",TotalWatingTime/s);
	printf("\n\t\t\tAverage Turn around Time is: = %d\n\n",TotalTurnAroundTime/s);
}
void scheduling(struct student list[], int s)
{
    int i, j;
    struct student temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].FTakenTime < list[j + 1].FTakenTime)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
            else if(list[j].FTakenTime == list[j + 1].FTakenTime)
            {
            	if(list[j].StudentId > list[j + 1].StudentId)
            	{
            	temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                }
			}
        }
    }
}
void waitingTime(struct student list[], int n)
{
	int j,total;
    list[0].WaitingTime=0;
    for(j=1;j<n;j++)
    {
        list[j].WaitingTime=list[j-1].WaitingTime+list[j-1].FTakenTime;
    }
}
void turnAroundTime(struct student list[], int n)
{
	int j,total;
    
    for(j=0;j<n;j++)
    {
        list[j].TurnAroundTime=list[j].WaitingTime+list[j].FTakenTime;
    }
}
int main()
{
    struct student data[20];
    int n,i;
    printf("Number of Students eating in mess? : ");
    scanf("%d", &n);
    input(data, n);
    scheduling(data, n);
    waitingTime(data,n);
    turnAroundTime(data,n);
    display(data, n);

}
