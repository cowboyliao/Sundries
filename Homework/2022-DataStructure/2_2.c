#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct Polynode
{
	ElemType Data;
	struct Polynode* next;
}Polynode, * Polylist;

Polylist Create(int n) //尾插法创建单链表
{
	Polylist Head; //头结点
	Polynode* r;
	Head = (Polylist)malloc(sizeof(Polynode));
	Head->next = NULL;
	r = Head;

	//录入数据
	for (int i = 0; i < n; i++)
	{
		Polylist p = (Polylist)malloc(sizeof(Polynode));
		printf("请输入第%d个数：", i + 1);
		scanf("%d", &p->Data);
		p->next = NULL;
		r->next = p;
		r = p;
	}

	return Head;
}

Polylist Merge(Polylist ListA, Polylist ListB) //链表合并
//将两个有序链表ListA、ListB按从小到大的顺序合并为一个新的有序链表ListC
{
	Polylist p, q, newp, temp, s, r; //newp为结果链表的头结点，r为尾指针
	newp = (Polylist)malloc(sizeof(Polynode));

	p = ListA->next;
	q = ListB->next;
	newp->next = NULL;
	r = newp;

	while (p != NULL && q != NULL)
	{
		//链表A的数据大于链表B的数据，将B的数据存入新多项式中
		if (p->Data > q->Data)
		{
			s = (Polylist)malloc(sizeof(Polynode));
			s->Data = q->Data;
			r->next = s;
			r = s;

			//释放多余结点内存空间
			temp = q;
			q = q->next;
			free(temp);
		}

		//链表A的数据小于链表B的数据，将A的数据存入新多项式中
		else
		{
			s = (Polylist)malloc(sizeof(Polynode));
			s->Data = p->Data;
			r->next = s;
			r = s;

			//释放多余结点内存空间
			temp = p;
			p = p->next;
			free(temp);
		}
	}

	//将剩余结点连至新的链表
	if (p == 0) r->next = q;
	else r->next = p;

	return newp;
}

void PrintList(Polylist L) //打印结果链表
{
	Polylist p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->Data);
		p = p->next;
	}
}

int main()
{
	//输入数据
	int n;
	Polylist List1, List2, List3;

	printf("输入第一个单链表的数据个数：");
	scanf("%d", &n);
	List1 = Create(n);

	printf("输入第二个单链表的数据个数：");
	scanf("%d", &n);
	List2 = Create(n);

	List3 = Merge(List1, List2);
	printf("结果为：");
	PrintList(List3);

	return 0;
}
