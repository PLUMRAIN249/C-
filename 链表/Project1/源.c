#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head;
    struct Node* p1;
    struct Node* p2;
    struct Node* p3;
    struct Node* p;

    p1 = malloc(sizeof(struct Node));
    p2 = malloc(sizeof(struct Node));
    p3 = malloc(sizeof(struct Node));

    p1->data = 10;
    p2->data = 20;
    p3->data = 30;

    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;

    head = p1;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);

        p = p->next;
    }

    return 0;
}





struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head;
    struct Node* p1;
    struct Node* p2;
    struct Node* p3;

    // 一开始是空链表
    head = NULL;

    // 创建第一个节点
    p1 = malloc(sizeof(struct Node));
    p1->data = 10;
    p1->next = NULL;

    // head 指向第一个节点
    head = p1;

    // 创建第二个节点
    p2 = malloc(sizeof(struct Node));
    p2->data = 20;
    p2->next = NULL;

    // 第一个节点连接第二个节点
    p1->next = p2;

    // 创建第三个节点
    p3 = malloc(sizeof(struct Node));
    p3->data = 30;
    p3->next = NULL;

    // 第二个节点连接第三个节点
    p2->next = p3;

    return 0;
}






struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* newNode;

    int n;
    int i;

    printf("请输入节点个数：");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        // 创建一个新节点
        newNode = malloc(sizeof(struct Node));

        // 输入数据
        printf("请输入第%d个数据：", i + 1);
        scanf("%d", &newNode->data);

        // 新节点暂时没有下一个节点
        newNode->next = NULL;

        // 如果这是第一个节点
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // 把新节点接到链表最后面
            tail->next = newNode;

            // tail 移动到最后一个节点
            tail = newNode;
        }
    }

    return 0;
}







//头部插入
struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    // 原来的链表
    struct Node* head = NULL;

    // 创建第一个节点
    struct Node* p1 = malloc(sizeof(struct Node));
    p1->data = 10;
    p1->next = NULL;

    head = p1;

    // 创建第二个节点
    struct Node* p2 = malloc(sizeof(struct Node));
    p2->data = 20;
    p2->next = NULL;

    p1->next = p2;

    // 创建第三个节点
    struct Node* p3 = malloc(sizeof(struct Node));
    p3->data = 30;
    p3->next = NULL;

    p2->next = p3;

    // ==================
    // 头部插入 5
    // ==================

    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = 5;

    newNode->next = head;
    head = newNode;

    // 遍历
    struct Node* p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}









//尾部插入      
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    // 创建三个原来的节点
    struct Node* p1 = malloc(sizeof(struct Node));
    struct Node* p2 = malloc(sizeof(struct Node));
    struct Node* p3 = malloc(sizeof(struct Node));

    p1->data = 10;
    p2->data = 20;
    p3->data = 30;

    p1->next = p2;
    p2->next = p3;
    p3->next = NULL;

    struct Node* head = p1;

    // ===== 尾部插入 =====

    // 1. 创建新节点
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->data = 40;
    newNode->next = NULL;

    // 2. 从头开始寻找最后一个节点
    struct Node* p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    // 3. 把新节点接到最后
    p->next = newNode;

    // ===== 遍历 =====

    p = head;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}


//删除第一个节点




struct Node* temp = head;

head = head->next;

free(temp);





//删除中间节点 data==20的节点






struct Node* p = head;

// 找到 20 前面的节点 10
while (p->next->data != 20)
{
    p = p->next;
}

struct Node* temp = p->next;

p->next = p->next->next;

free(temp);





//删除最后一个节点





struct Node* p = head;

// 找到最后一个节点前面的节点
while (p->next != tail)
{
    p = p->next;
}

struct Node* temp = tail;

p->next = NULL;

tail = p;

free(temp);




//查找链表中的某个值
int x;

printf("请输入要查找的数据：");
scanf("%d", &x);

struct Node* p = head;

while (p != NULL)
{
    if (p->data == x)
    {
        printf("找到了！\n");
        break;
    }

    p = p->next;
}

if (p == NULL)
{
    printf("没找到！\n");
}   




//修改某个值
int oldData;
int newData;

printf("请输入要修改的数据：");
scanf("%d", &oldData);

printf("请输入修改后的数据：");
scanf("%d", &newData);

struct Node* p = head;

while (p != NULL)
{
    if (p->data == oldData)
    {
        p->data = newData;

        printf("修改成功！\n");
        break;
    }

    p = p->next;
}

if (p == NULL)
{
    printf("没有找到这个节点！\n");
}
