#include<stdio.h> 
#define KeyType int
typedef struct SeqList{
	int key; 
}SeqList;
int BinSearch(SeqList R[],int n,KeyType k)
{
int low=0,high=n-1,mid,count=0;
while(low<=high)
{
mid=(low+high)/2;
printf("第%d次查找：在[ %d ,%d]中找到元素R[%d]:%d\n ",++count,low,high,mid,R[mid].key);
if(R[mid].key==k)
return mid;
if(R[mid].key>k)
high=mid-1;
else
low=mid+1;
}
return -1;
}
int main()
{
	int	result,line[]={5,7,9,12,15,18,20,22,25,30,100};
	SeqList box[11];
	for(int i=0;i<11;i++)
	{
		box[i].key=line[i];
	}
	printf("请输入你要查找的整数");
	int k;
	scanf("%d",&k);
	result=BinSearch(box,10,k);
	if(result!=-1)
	{
		printf("查找成功,位置是:%d",result);
	}
	else
	{
		printf("元素未在列表里面");
	}
}
