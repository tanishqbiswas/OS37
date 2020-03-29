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

int main()
{
    struct student data[20];
    int n,i;
    printf("Number of Students eating in mess? : ");
    scanf("%d", &n);
    input(data, n);
}
 
