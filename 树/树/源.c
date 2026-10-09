#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//二叉树就是每个节点最多有两个子节点
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

int main()
{
    struct Node* root;
    struct Node* p1;
    struct Node* p2;

    root = malloc(sizeof(struct Node));
    p1 = malloc(sizeof(struct Node));
    p2 = malloc(sizeof(struct Node));

    if (root == NULL || p1 == NULL || p2 == NULL)//有任何一个申请内存失败 就释放内存
    {
        free(root);
        free(p1);
        free(p2);
        return 1;
    }

    root->data = 10;
    p1->data = 20;
    p2->data = 30;

    root->left = p1;
    root->right = p2;

    p1->left = NULL;
    p1->right = NULL;

    p2->left = NULL;
    p2->right = NULL;

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);

    free(p1);
    free(p2);
    free(root);

    return 0;
}





//节点创造函数
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* p;

    p = malloc(sizeof(struct Node));

    if (p == NULL)
    {
        return NULL;
    }

    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

int main()
{
    struct Node* root = createNode(10);
    struct Node* p1 = createNode(20);
    struct Node* p2 = createNode(30);

    if (root == NULL || p1 == NULL || p2 == NULL)
    {
        free(root);
        free(p1);
        free(p2);
        return 1;
    }

    root->left = p1;
    root->right = p2;

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);

    free(p1);
    free(p2);
    free(root);

    return 0;
}

                                                               A
                                                          B           C
                                                      D      E        F


//前序遍历（根左右） ABDECF
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void preorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);

    preorder(root->left);

    preorder(root->right);
}
//中序遍历（左根右） DBEAFC
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    printf("%c ", root->data);

    inorder(root->right);
}
//后序遍历（左右根） DEBFCA
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void postorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    printf("%c ", root->data);
}
//层序遍历 ABCDEF
void levelOrder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    struct Node* queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        struct Node* p = queue[front++];

        printf("%c ", p->data);

        if (p->left != NULL)
        {
            queue[rear++] = p->left;
        }

        if (p->right != NULL)
        {
            queue[rear++] = p->right;
        }
    }
}








//二叉树的常见算法
1.计算节点总数：左子树节点总数+右子树节点总数+1
int countNodes(struct Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = countNodes(root->left);

    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}
2.计算叶子节点总数
int countLeaves(struct Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int leftCount = countLeaves(root->left);

    int rightCount = countLeaves(root->right);

    return leftCount + rightCount;
}
3.树的高度
int getHeight(struct Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = getHeight(root->left);

    int rightHeight = getHeight(root->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}
4.查找指定节点
struct Node* searchNode(struct Node* root, char target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        return root;
    }

    struct Node* p = searchNode(root->left, target);

    if (p != NULL)
    {
        return p;
    }

    return searchNode(root->right, target);
}





//二叉搜索树
它有三个基本规则：
1. 左子树中所有节点的值都小于根节点的值。
2. 右子树中所有节点的值都大于根节点的值。
3. 左右子树也必须分别满足二叉搜索树的规则。
//查找代码
struct Node* search(struct Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}


//插入算法
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
