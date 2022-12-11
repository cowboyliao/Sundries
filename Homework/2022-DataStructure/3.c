#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define N 40
//中序转后序
typedef char NodeType;
typedef struct stack//栈
{
    NodeType data[N];
    int top;
} STACK;

void Push(STACK* stack, NodeType data)//入栈
{
    if (stack->top <= N)
        memcpy(&stack->data[stack->top], &data, sizeof(NodeType));
    stack->top = stack->top + 1;
}

NodeType Pop(STACK* stack)//出栈
{
    if (stack->top > 0)
    {
        stack->top = stack->top - 1;
        return stack->data[stack->top];
    }
    else
    {
        return '0';
    }
}

int isops(char a)//是否为符号
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isdig(char a)//是否为数字
{
    if (a >= '0' && a <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int opsadv(char a)//符号优先级
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    if (a == '*' || a == '/')
    {
        return 2;
    }
    return 0;
}

void result(char a, char b[])
{
    static int k = 0;
    b[k] = a;
    k++;
}

int IsEmpty(STACK s)
{
    if (s.top == 0)
        return 1;
    else
        return 0;
}


//后序表达式求值所用函数

typedef int NodeType1;


typedef struct stack1 //计算栈
{
    NodeType1 data1[N];
    int top1;
} STACK1;

void Push1(STACK1* stack1, NodeType1 data1)
{
    memcpy(&stack1->data1[stack1->top1], &data1, sizeof(NodeType1));
    stack1->top1 = stack1->top1 + 1;
}

NodeType1 Pop1(STACK1* stack1)
{
    stack1->top1 = stack1->top1 - 1;
    return stack1->data1[stack1->top1];
}

NodeType1 OpInt(int w1, int w2, char op)
{
    NodeType1 resu;
    switch (op)
    {
    case '+':
        resu = w1 + w2;
        break;
    case '-':
        resu = w1 - w2;
        break;
    case '*':
        resu = w1 * w2;
        break;
    case '/':
        resu = w1 / w2;
        break;
    }
    return resu;
}


int Change(int q)
{
    if (q >= 48 && q <= 57)
        q = q - 48;
    return q;
}


//用户界面
int main()
{
    //转换所用
    char word[N];//存储用户输入的表达式
    char res[N];//用于存储转换后的表达式
    char cun;
    STACK stack;
    stack.top = 0;
    printf("请输入你的算术四则混合运算表达式:\n");
    fgets(word, N, stdin);
    int m = 0;//记录入栈次数
    int m1 = 0;//记录（后入栈次数
    int i, j, p;
    NodeType d1 = 'A', d2 = 'A';//辅助出入栈
    for (i = 0; word[i] != '\0'; i++)
    {
        if (isdig(word[i]))
        {
            result(word[i], res);
            //printf("%c",word[i]);
        }
        else if (isops(word[i]))
        {
            d1 = word[i];
            if (d1 == '(')
            {
                //d2=d1;
                Push(&stack, d1);
                m1++;
                m--;//未改变d2的值，m会多1
            }
            else if (d1 == ')')
            {
                while (stack.data[stack.top - 1] != '(')
                {
                    cun = Pop(&stack);
                    result(cun, res);
                }

                cun = Pop(&stack);
                d2 = 'A';
                m1 = 0;

            }
            else if (d2 == 'A')
            {
                d2 = d1;
                Push(&stack, d1);
                m++;
                if (m1 != 0)
                {
                    m1++;
                }
            }
            else if (opsadv(d1) > opsadv(d2))//
            {
                Push(&stack, d1);
                m++;
                if (m1 != 0)
                {
                    m1++;
                }
                d2 = d1;
            }
            else if (opsadv(d1) <= opsadv(d2))
            {
                for (j = 0; j < m; j++)
                {
                    cun = Pop(&stack);
                    result(cun, res);
                    //printf("%c",cun);
                }
                Push(&stack, d1);
                m = 1;
                d2 = d1;
            }
        }
    }
    while (!IsEmpty(stack))
    {
        cun = Pop(&stack);
        result(cun, res);
    }
    result('\0', res);
    putchar('\n');
    printf("最后得到的分解表达式为:");
    for (p = 0; res[p] != '\0'; p++)//打印存入数组中的内容
    {
        printf("%c ", res[p]);
    }
    printf("\n");
    putchar('\n');

    //求值所用
    int s;
    NodeType1 w1, w2, w3;
    STACK1 stack1;
    stack1.top1 = 0;
    for (s = 0; res[s] != '\0'; s++) //遍历数组
    {
        if (isdig(res[s]))
        {
            w1 = Change((int)(res[s]));
            Push1(&stack1, w1);//是数字则入栈
        }
        else
        {
            w2 = Pop1(&stack1);
            //printf("w2=%d\n",w2);
            w1 = Pop1(&stack1);//取出两个数字
            //printf("w1=%d\n",w1);
            w3 = OpInt(w1, w2, res[s]);
            //printf("w3=%d\n",w3);//计算过程
            Push1(&stack1, w3);//结果入栈
        }
    }
    w1 = Pop1(&stack1);
    printf("最后的结果是:%d\n", w1);
    printf("姓名:廖青松,学号:2021212375");
}
