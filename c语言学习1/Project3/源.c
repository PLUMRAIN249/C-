#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Product
{
    int id;
    char name[30];
    float price;
    int quantity;
};


/* 显示所有商品 */
void printProducts(int count, struct Product* p)
{
    int i;

    if (count == 0)
    {
        printf("还没有商品信息！\n");
        return;//void函数不需要返回具体值 只需要return告诉他函数结束了就行
    }

    printf("\n===== 所有商品 =====\n");

    for (i = 0; i < count; i++)
    {
        printf("编号：%d\n", p[i].id);
        printf("名称：%s\n", p[i].name);
        printf("价格：%.2f\n", p[i].price);
        printf("数量：%d\n", p[i].quantity);
        printf("--------------------\n");
    }
}


/* 添加商品 */
void addProduct(struct Product** p, int* count, int* capacity)//要修改就要带一个*指针 第一个有两个*是因为要修改的就是个*变量
{
    if (*count >= *capacity)
    {
        *capacity = *capacity + 1;

        struct Product* temp;
        temp = realloc(*p, (*capacity) * sizeof(struct Product));//这样写更安全 

        if (temp == NULL)
        {
            printf("内存扩展失败！\n");
            return;
        }

        *p = temp;
    }

    printf("请输入商品编号：");
    scanf("%d", &(*p)[*count].id);

    printf("请输入商品名称：");
    scanf("%s", (*p)[*count].name);

    printf("请输入商品价格：");
    scanf("%f", &(*p)[*count].price);

    printf("请输入商品数量：");
    scanf("%d", &(*p)[*count].quantity);

    (*count)++;

    printf("商品添加成功！\n");
}


/* 查询商品 */
void searchProduct(int count, struct Product* p)
{
    int searchid;
    int found = 0;
    int i;

    printf("请输入要查询的商品编号：");
    scanf("%d", &searchid);

    for (i = 0; i < count; i++)
    {
        if (searchid == p[i].id)
        {
            found = 1;

            printf("\n已找到商品！\n");
            printf("编号：%d\n", p[i].id);
            printf("名称：%s\n", p[i].name);
            printf("价格：%.2f\n", p[i].price);
            printf("数量：%d\n", p[i].quantity);

            break;
        }
    }

    if (found == 0)
    {
        printf("未找到该商品信息！\n");
    }
}


/* 修改商品 */
void modifyProduct(int count, struct Product* p)
{
    int searchid;
    int found = 0;
    int i;

    printf("请输入要修改的商品编号：");
    scanf("%d", &searchid);

    for (i = 0; i < count; i++)
    {
        if (searchid == p[i].id)
        {
            found = 1;

            struct Product* q = &p[i];

            printf("找到商品：%s\n", q->name);

            printf("请输入新的商品名称：");
            scanf("%s", q->name);

            printf("请输入新的商品价格：");
            scanf("%f", &q->price);

            printf("请输入新的商品数量：");
            scanf("%d", &q->quantity);

            printf("修改成功！\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("未找到该商品信息！\n");
    }
}


/* 删除商品 */
void deleteProduct(int* count, struct Product* p)
{
    int searchid;
    int found = 0;
    int i;
    int j;

    printf("请输入要删除的商品编号：");
    scanf("%d", &searchid);

    for (i = 0; i < *count; i++)
    {
        if (searchid == p[i].id)
        {
            found = 1;

            /*
                从当前位置开始，
                后面的商品依次向前移动
            */
            for (j = i; j < *count - 1; j++)
            {
                p[j] = p[j + 1];
            }

            (*count)--;

            printf("删除成功！\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("未找到该商品信息！\n");
    }
}


/* 查找最贵商品 */
void findMostExpensive(int count, struct Product* p)
{
    int i;
    int maxIndex = 0;

    if (count == 0)
    {
        printf("还没有商品信息！\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (p[i].price > p[maxIndex].price)
        {
            maxIndex = i;
        }
    }

    printf("\n===== 最贵商品 =====\n");
    printf("编号：%d\n", p[maxIndex].id);
    printf("名称：%s\n", p[maxIndex].name);
    printf("价格：%.2f\n", p[maxIndex].price);
    printf("数量：%d\n", p[maxIndex].quantity);
}


/* 统计库存总量 */
void totalQuantity(int count, struct Product* p)
{
    int i;
    int sum = 0;

    for (i = 0; i < count; i++)
    {
        sum += p[i].quantity;
    }

    printf("库存商品总数量：%d\n", sum);
}


/* 统计库存总价值 */
void totalValue(int count, struct Product* p)
{
    int i;
    float sum = 0;

    for (i = 0; i < count; i++)
    {
        sum += p[i].price * p[i].quantity;
    }

    printf("库存总价值：%.2f 元\n", sum);
}


/* 商品名称统计 */
void nameStatistics(int count, struct Product* p)
{
    int i;
    int totalLength = 0;

    if (count == 0)
    {
        printf("还没有商品信息！\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalLength += strlen(p[i].name);
    }

    printf("商品总数：%d\n", count);
    printf("商品名称总字符数：%d\n", totalLength);
}


/* 按价格从低到高排序 */
void sortProducts(int count, struct Product* p)
{
    int i;
    int j;

    struct Product temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if (p[j].price > p[j + 1].price)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("排序完成！\n");
}


/* 保存到文件 */
void saveToFile(int count, struct Product* p)
{
    FILE* fp;
    int i;

    fp = fopen("products.txt", "w");

    if (fp == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%d %s %.2f %d\n",
            p[i].id,
            p[i].name,
            p[i].price,
            p[i].quantity);
    }

    fclose(fp);

    printf("商品信息保存成功！\n");
}


/* 从文件读取 */
void loadFromFile(struct Product** p, int* count, int* capacity)
{
    FILE* fp;
    struct Product temp;

    fp = fopen("products.txt", "r");

    if (fp == NULL)
    {
        printf("文件打开失败，可能还没有保存过商品。\n");
        return;
    }

    *count = 0;

    while (fscanf(fp, "%d %s %f %d",
        &temp.id,
        temp.name,
        &temp.price,
        &temp.quantity) == 4)
    {
        if (*count >= *capacity)
        {
            *capacity = *capacity + 1;

            struct Product* newp;

            newp = realloc(*p,
                (*capacity) * sizeof(struct Product));

            if (newp == NULL)
            {
                printf("内存扩展失败！\n");
                fclose(fp);
                return;
            }

            *p = newp;
        }

        (*p)[*count] = temp;

        (*count)++;
    }

    fclose(fp);

    printf("商品信息读取成功！\n");
}


/* 主函数 */
int main()
{
    int capacity;
    int count = 0;
    int choice;
    int i;

    printf("请输入初始商品容量：");
    scanf("%d", &capacity);

    struct Product* p;

    p = malloc(capacity * sizeof(struct Product));

    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return 1;
    }


    do
    {
        printf("\n");
        printf("===== 商品库存管理系统 =====\n");
        printf("1. 添加商品\n");
        printf("2. 显示所有商品\n");
        printf("3. 查询商品\n");
        printf("4. 修改商品\n");
        printf("5. 删除商品\n");
        printf("6. 查找最贵商品\n");
        printf("7. 统计库存总量\n");
        printf("8. 统计库存总价值\n");
        printf("9. 商品名称统计\n");
        printf("10. 按价格排序\n");
        printf("11. 保存到文件\n");
        printf("12. 从文件读取\n");
        printf("0. 退出\n");
        printf("==============================\n");

        printf("请输入你的选择：");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1:
            addProduct(&p, &count, &capacity);
            break;

        case 2:
            printProducts(count, p);
            break;

        case 3:
            searchProduct(count, p);
            break;

        case 4:
            modifyProduct(count, p);
            break;

        case 5:
            deleteProduct(&count, p);
            break;

        case 6:
            findMostExpensive(count, p);
            break;

        case 7:
            totalQuantity(count, p);
            break;

        case 8:
            totalValue(count, p);
            break;

        case 9:
            nameStatistics(count, p);
            break;

        case 10:
            sortProducts(count, p);
            break;

        case 11:
            saveToFile(count, p);
            break;

        case 12:
            loadFromFile(&p, &count, &capacity);
            break;

        case 0:
            printf("程序结束！\n");
            break;

        default:
            printf("输入错误，请重新选择！\n");
        }

    } while (choice != 0);


    free(p);

    return 0;
}