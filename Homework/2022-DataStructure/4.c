#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int arrive;//到达时间 
    int treat;//需要占用的时间 
}QNODE;
typedef struct node {
    QNODE data;
    struct node* next;
}LNODE;
LNODE* front, * rear;
void inQueue(QNODE e)//入队
{
    LNODE* p = (LNODE*)malloc(sizeof(LNODE));
    p->data = e;
    p->next = NULL;
    if (front == NULL)
        front = rear = p;
    else
    {
        rear->next = p;
        rear = p;
    }
}
int outQueue(QNODE* e) // 出队
{
   LNODE * s;
   if (front == NULL)
       return 0;//队空
   *e = front->data;
   s = front;
   front = front->next;
   if (front == NULL)
       rear = NULL;
   free(s);
   return 1;
}

int main(void)
{ 
    FILE* fp;
    QNODE temp, former;
    //spareTime表示业务员的总空闲时间，clock表示当前时间，waitTime表示客户的总等待时间 
     //count客户总数  
    int have = 0, spareTime = 0, clock = 0, waitTime = 0, count = 0, finishTime;
    if ((fp = fopen("data.txt", "r")) == NULL)
    {
        printf("文件打开出错");
        return 0;
    }
    front = rear = NULL;
    have = fscanf(fp, "%d %d", &temp.arrive, &temp.treat);
    do {
        if (front == NULL && have - 2 == 0)
        {
            spareTime = spareTime + temp.arrive - clock;
            clock = temp.arrive;
            inQueue(temp);
            have = fscanf(fp, "%d %d", &temp.arrive, &temp.treat);
        }
        count++;
        outQueue(&former);
        waitTime = waitTime + (clock - former.arrive);
        finishTime = clock + former.treat;
        while (have - 2 == 0 && temp.arrive <= finishTime)
        {
            inQueue(temp);
            have = fscanf(fp, "%d %d", &temp.arrive, &temp.treat);
        }
        clock = finishTime;
    } while (have - 2 == 0 || front != NULL);
    printf("模拟总时间：%d\n业务员等待时间：%d\n客户平均等待时间：%f\n", clock, spareTime, (double)waitTime / count);
    printf("客户人数：%d\n总等待时间：%d\n", count, waitTime);
    return 0;
}
