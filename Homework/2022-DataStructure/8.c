#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义结构体
struct Student
{
	char  name;//姓名
	int  score;//分数
}stu[11];

void BubbleSort()
{
	//冒泡排序
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (stu[j].score < stu[j + 1].score)
			{
				stu[10] = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = stu[10];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%c,%d\t", stu[i].name, stu[i].score);
	}
}

void SelectionSort()
{
	//选择排序
	for (int i = 0; i < 9; i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (stu[i].score < stu[j].score)
			{
				stu[10] = stu[j];
				stu[j] = stu[i];
				stu[i] = stu[10];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%c,%d\t", stu[i].name, stu[i].score);
	}
}

int main()
{
	//生成伪随机数，导入数据
	time_t t;
	srand((unsigned)time(&t));

	//冒泡排序
	printf("==============================冒泡排序==============================");
	for (int i = 0; i < 10; i++)
	{
		stu[i].name = 65 + i;
		stu[i].score = rand() % 100;
	}
	printf("\n原始数据：\n");
	for (int i = 0; i < 10; i++) {
		printf("%c,%d\t", stu[i].name, stu[i].score);
	}
	printf("\n进行冒泡排序，结果为：\n");
	BubbleSort();
	printf("\n\n==============================选择排序==============================");
	for (int i = 0; i < 10; i++)
	{
		stu[i].name = 65 + i;
		stu[i].score = rand() % 100;
	}
	printf("\n原始数据：\n");
	for (int i = 0; i < 10; i++) {
		printf("%c,%d\t", stu[i].name, stu[i].score);
	}
	printf("\n进行选择排序，结果为：\n");
	SelectionSort();
	putchar('\n');
}
