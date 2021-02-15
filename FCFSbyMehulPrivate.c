#include<stdio.h>
#include<stdlib.h>

struct node {
int Process;
int ArrivalTime;
int BurstTime;
int TurnAroundTime;
int WaitingTime;
struct node *next;
};
struct node *start = NULL;

int maximumArrivalTime;
int flag = 0;
int startTime = 0;
int currentTime = 0;

void createNode()
{
    struct node *temp = start;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Process Number : ");
    scanf("%d",&p->Process);

    printf("\nEnter Arrival Time : ");
    scanf("%d",&p->ArrivalTime);

    printf("\nEnter Burst Time : ");
    scanf("%d",&p->BurstTime);

    p->TurnAroundTime = 0;
    p->WaitingTime = 0;
    p->next=NULL;

    if(start == NULL){
        start = p;
    }

    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void main()
{
    int n,i;
    printf("\n ENTER THE NUMBER OF PROCESS : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        createNode();
    }

    printf("\n TOTAL PROCESSES IN THE SYSTEM : ");
    struct node *x = start;

    while(x != NULL){
        printf(" %d ",x->Process);
        x = x->next;
    }

    /*Find Maximum of Arrival Time*/
    struct node *m =start;
    maximumArrivalTime = start->ArrivalTime;
    while(m != NULL)
    {
        if(m->ArrivalTime > maximumArrivalTime)
            {
                maximumArrivalTime = m->ArrivalTime;
            }
            m = m->next;
    }
    printf("\n MAXIMUM Arrival Time is = %d \n",maximumArrivalTime);

    printf(" NOTE : Output format is : TIME <PROCESS NO> TIME <PROCESS NO.> ..... \n");

    for(i=0;i<=maximumArrivalTime;i++)
    {
        x=start;
        
        //Traverse the whole list of processes, And for every second print the process.
        //i.e For t=0 , traverse through the list of processes and check which process has AT = 0 and print it
        while(x != NULL)
            {
                if(x->ArrivalTime == i)
                {
                    //Calculate statre time. This is done once, Therefore once its done set flag=1 and execute this part only when flag=0 
                    if(flag == 0)
                    {
                        startTime = x->ArrivalTime;
                        currentTime = startTime;
                        printf(" %d ",startTime);
                        flag = 1;
                    }

                    printf(" < %d > ",x->Process);

                    if(currentTime<i){
                        currentTime++;
                    }
                    currentTime = currentTime + x->BurstTime;
                    printf(" %d ",currentTime);


                    x->TurnAroundTime = currentTime - x->ArrivalTime;
                    x->WaitingTime = x->TurnAroundTime - x->BurstTime;
                }

                else{
                    //DO NOTHING
                }
                x = x -> next;
            }
    }

    printf("\n");
    printf("\nDETAILS OF EACH PROCESS : ");
    int totalTurnAroundTime = 0;
    int totalWaitingTime = 0;
    m =start;
    while(m != NULL)
    {
        printf("\n Process No = %d : Arrival Time = %d : Burst Time = %d : Turn Around Time = %d : Waiting Time = %d ",m->Process,m->ArrivalTime,m->BurstTime,m->TurnAroundTime,m->WaitingTime);
        totalTurnAroundTime = totalTurnAroundTime + m->TurnAroundTime;
        totalWaitingTime = totalWaitingTime + m->WaitingTime;
        m = m->next;
    }

    printf("\n Average Waiting Time = %f ",(float)totalWaitingTime/n);
    printf("\n Average Around Time = %f ",(float)totalTurnAroundTime/n);

}
