#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList* L)/*初始化顺序表L*/
{
    L->size = 0;/*定义初始数据元素个数*/
}

int ListLength(SeqList L)/*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(SeqList* L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if (L->size >= MaxSize)
    {
        printf("顺序表已满无法插入! \n");
        return 0;
    }
    else if (i < 0 || i > L->size)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        for (j = i; j < L->size; j--)
            L->list[j + 1] = L->list[j];/*为插入做准备*/
        L->list[i] = x;/*插入*/
        L->size++;/*元素个数加1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType* x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if (i < 0 || i > L.size - 1)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}

int Merge(SeqList* L1, SeqList* L2,SeqList* L3)
//输入两个有序表L1，L2，将其按从小到大的顺序合并为一个新的有序表L3
//若操作成功，则返回1；若操作失败，则返回0
{
    //合法性检查
    if (L1->size + L2->size > MaxSize)
        return 0;

    int i = 0, j = 0, k = 0;//分别用于表1、2、3的计数
    L3->size = L1->size + L2->size;//合并表长

    //按从小到大的顺序合并两个有序表1,2
    while (i <= L1->size && j <= L2->size)
    {
        if (L1->list[i] > L2->list[j])
            L3->list[k++] = L2->list[j++];
        else
            L3->list[k++] = L1->list[i++];
    }

    //将剩余数据导入表3
    k--;
    if (i <= L1->size)
    {
        while (i <= L1->size)
        {
            L3->list[k++] = L1->list[i++];
        }
    }
    else
    {
        L3->list[k++] = L2->list[j++];
    }

    return 1;
}

int main(void)
{
    SeqList L1, L2, L3;
    int i, x;

    ListInitiate(&L1);
    ListInitiate(&L2);
    ListInitiate(&L3);

    for (i = 0; i < 10; i++)
        ListInsert(&L1, i, i * 2);
    for (i = 0; i < 5; i++)
        ListInsert(&L2, i, i * 2 - 1);

    Merge(&L1, &L2, &L3);

    for (i = 0; i < ListLength(L3); i++)
    {
        ListGet(L3, i, &x);
        printf("%d ", x);
    }
}
