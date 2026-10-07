#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//基本知识
int main()
{
    int stack[100];
    int top = -1;

    // 入栈
    top++;
    stack[top] = 10;

    top++;
    stack[top] = 20;

    top++;
    stack[top] = 30;

    // 出栈
    int x = stack[top];
    top--;

    printf("出栈元素：%d\n", x);

    return 0;
}








//用数组构建栈
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// 入栈
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("栈满了，无法入栈\n");
        return;
    }

    top++;
    stack[top] = data;
}

// 出栈
int pop()
{
    if (top == -1)
    {
        printf("栈为空，无法出栈\n");
        return -1;
    }

    int data = stack[top];
    top--;

    return data;
}

// 查看栈顶
int peek()
{
    if (top == -1)
    {
        printf("栈为空\n");
        return -1;
    }

    return stack[top];
}

// 判断是否为空
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// 判断是否已满
int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int main()
{
    push(10);
    push(20);
    push(30);

    printf("栈顶：%d\n", peek());

    printf("出栈：%d\n", pop());
    printf("出栈：%d\n", pop());

    printf("现在的栈顶：%d\n", peek());

    return 0;
}