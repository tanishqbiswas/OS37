#include <stdio.h>

struct student
{
    int StudentId;
    int FTakenTime;
};

void input(struct student list[], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf ("\n\nEnter data for Student #%d", i + 1);
        
        printf("\nEnter Student id : ");
        scanf("%d", &list[i].StudentId);

        printf("Enter time taken for Food (minuts): ");
        scanf("%d", &list[i].FTakenTime);
    } 
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

int main()
{
    struct student data[20];
    int n,i;
    printf("Number of Students eating in mess? : ");
    scanf("%d", &n);
    input(data, n);
    scheduling(data, n);
}
 
