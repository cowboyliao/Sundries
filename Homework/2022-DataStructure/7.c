#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct
{
	KeyType key;//关键字
	char rec;//记录
}SeqList[8];

//顺序查找

int SeqSearch(SeqList R, int n, KeyType k)
{
	int i = 0;
	while (i < n && R[i].key != k)
	{
		printf("%d ", R[i].key);
		i++;
	}
	if (i >= n)
		return -1;
	else
	{
		printf("%d ", R[i].key);
		return i;
	}
}

//二分查找
int BinSearch(SeqList R, int n, KeyType k)
{
	int low = 0, high = n - 1, mid, count = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("第%d次查找：在[%d,%d]中找到元素R[%d]:%d\n", ++count, low, high, mid, R[mid].key);
		if (R[mid].key == k)
			return mid;
		if (R[mid].key > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	SeqList R;
	//顺序表赋值
	for (int i = 0; i < 8; i++)
	{
		R[i].key = i + 1;
		R[i].rec = i + 65;
	}
	//打印顺序表存储的记录
	printf("表中的数据为：\n");
	for (int i = 0; i < 8; i++)
		printf("%d------%c,%d\n", i + 1, R[i].rec, R[i].key);
	//使用顺序查找，查找关键字为4的记录
	printf("---------------------------\n");
	printf("使用顺序查找，查找关键字为4的记录\n");
	int pos_1;
	pos_1 = SeqSearch(R, 8, 4);
	printf("\n关键字为4的记录位置为：%d，该条记录为：%c，%d\n", pos_1 + 1, R[pos_1].rec, R[pos_1].key);

	//使用二分查找，查找关键字为7的记录
	printf("---------------------------\n");
	printf("使用二分查找，查找关键字为7的记录\n\n");
	int pos_2;
	pos_2 = BinSearch(R, 8, 7);
	printf("\n关键字为7的记录位置为：%d，该条记录为：%c，%d\n", pos_2 + 1, R[pos_2].rec, R[pos_2].key);
	return 0;
}
