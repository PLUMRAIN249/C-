#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//队列基本形式
int main()
{
    int queue[5];
    int front = 0;
    int rear = 0;

    // 入队 10
    queue[rear] = 10;
    rear++;

    // 入队 20
    queue[rear] = 20;
    rear++;

    // 入队 30
    queue[rear] = 30;
    rear++;

    // 出队
    int data = queue[front];
    front++;

    printf("出队元素：%d\n", data);

    // 输出现在队列中的元素
    printf("现在队列：\n");

    for (int i = front; i < rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
//用函数实现
int queue[5];
int front = 0;
int rear = 0;

// 入队
void enqueue(int data)
{
    queue[rear] = data;
    rear++;
}

// 出队
int dequeue()
{
    int data = queue[front];
    front++;

    return data;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    int data = dequeue();

    printf("出队元素：%d\n", data);

    printf("现在队列：\n");

    for (int i = front; i < rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}





//简单循环队列

#define MAX 5

int queue[MAX];
int front = 0;
int rear = 0;

//入队
void enqueue(int data)
{
    queue[rear] = data;
    rear = (rear + 1) % MAX;
}

//出队
int dequeue()
{
    int data = queue[front];
    front = (front + 1) % MAX;

    return data;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("出队：%d\n", dequeue());
    printf("出队：%d\n", dequeue());

    enqueue(50);
    enqueue(60);

    printf("现在队列：\n");

    int i = front;

    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }

    return 0;
}
//循环队列判断队满队空：故意空出一个位置 明明有n个位置 我真正只装n-1个元素 永远要留一个空位！！
循环队列 MAX = 5

队空：

[][][][][]
↑
front
↑
rear

front == rear


队满：

[10] [20] [30] [40]   []
↑                    ↑
front                rear

(rear + 1) % MAX == front