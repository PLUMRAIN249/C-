# C语言补充知识速查笔记

基础概念 · 核心语法 · 主要代码示例

整理范围：位运算、typedef、enum、union、static/extern/const、函数指针、指针数组与数组指针、预处理、条件编译、多文件编程。适合复习和上传 GitHub。

## 位运算

按二进制位操作：& 按位与（都为1才为1）；| 按位或（有1即1）；^ 异或（不同为1）；~ 逐位取反；<< 左移；>> 右移。

```c
unsigned int a = 5, b = 3; // 5=0101, 3=0011
printf("%u\n", a & b);  // 1
printf("%u\n", a | b);  // 7
printf("%u\n", a ^ b);  // 6
printf("%u\n", a << 1); // 10
printf("%u\n", a >> 1); // 2
```

注意：移位时优先使用无符号整数；移位位数不能为负或大于等于类型位宽。

## typedef 类型别名

```c
typedef 为已有类型起别名，不会创建新类型。结构体配合 typedef 可省去反复写 struct。
```

```c
typedef unsigned int UINT;
typedef struct Student {
    char name[20];
    int age;
} Student;
Student s = {"Li", 20};
UINT n = 10;
```

## enum 枚举

用于表示一组有名称的整数常量；默认从0开始依次递增，也可手动指定。

```c
typedef enum { PENDING, RUNNING, DONE = 5 } Status;
Status s = RUNNING;
printf("%d\n", s); // 1
```

## union 联合体

联合体的所有成员共享同一块存储空间；通常只把最近写入的成员作为当前有效数据来使用。

```c
union Data {
    int i;
    float f;
};
union Data d;
d.i = 10;
printf("%d\n", d.i);
d.f = 3.5f;
printf("%.1f\n", d.f);
```

注意：union 不像 struct 那样为每个成员分别保留独立空间。

## static、extern、const

static 局部变量只初始化一次，函数调用结束后仍保留值；文件作用域 static 限制名称的链接范围。extern 通常声明在其他地方定义的变量；const 限制修改。

```c
#include <stdio.h>
void count(void) {
    static int n = 0;
    printf("%d ", ++n);
}
int global_score = 95;
int main(void) {
    extern int global_score;
    const int limit = 100;
    count(); count(); count(); // 1 2 3
    printf("%d %d", global_score, limit);
    return 0;
}
```

注意：const int *p：不能通过 p 改值；int *const p：p 本身不能改指向。

## 函数指针

函数指针保存兼容函数的地址，可通过指针调用函数，也可把函数作为参数传给其他函数（回调）。

```c
#include <stdio.h>
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
void calc(int a, int b, int (*op)(int,int)) {
    printf("%d\n", op(a,b));
}
int main(void) {
    int (*p)(int,int) = add;
    printf("%d\n", p(3,5)); // 8
    calc(10, 5, sub);        // 5
    return 0;
}
```

注意：int (*p)(int,int) 是函数指针；int *p(int,int) 是返回 int* 的函数声明。

## 指针数组与数组指针

```c
int *p[3]：p 是数组，元素为指针。int (*p)[3]：p 是指针，指向包含3个 int 的数组。
```

```c
int a = 10, b = 20, c = 30;
int *ptrs[3] = {&a, &b, &c};
printf("%d\n", *ptrs[1]); // 20

int arr[3] = {5, 10, 15};
int (*pa)[3] = &arr;
printf("%d\n", (*pa)[2]); // 15

int matrix[2][3] = {{1,2,3},{4,5,6}};
int (*row)[3] = matrix;
printf("%d\n", row[1][2]); // 6
```

## #include 与 #define

预处理在编译之前处理指令。#include 包含头文件；#define 定义宏，进行记号替换。带参数的宏要注意括号和副作用。

```c
#include <stdio.h>
#define MAX 100
#define SQUARE(x) ((x) * (x))
int main(void) {
    int a[MAX] = {0};
    printf("%d %d\n", MAX, SQUARE(2+3)); // 100 25
    return 0;
}
```

注意：不要使用 SQUARE(i++) 这样的调用，宏可能多次求值；简单计算优先考虑函数。

## 条件编译

条件编译决定某些源代码是否参与编译：#ifdef 检查宏是否已定义；#ifndef 检查是否未定义；#if 检查预处理表达式；#else 否则；#endif 结束。

```c
#define DEBUG 0
#ifdef DEBUG
    printf("DEBUG defined\n"); // 仍会保留
#endif
#if DEBUG == 1
    printf("Debug mode\n");
#else
    printf("Normal mode\n");
#endif
```

注意：这段是放在函数体内的示意片段；#define DEBUG 0 仍算“已定义”。

## 多文件编程（.h 与 .c）

头文件通常放声明，源文件放实现；main.c 包含头文件后调用函数。两个 .c 文件都要参与编译和链接。

## math_utils.h

```c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H
int add(int a, int b);
#endif
```

## math_utils.c

```c
#include "math_utils.h"
int add(int a, int b) {
    return a + b;
}
```

## main.c

```c
#include <stdio.h>
#include "math_utils.h"
int main(void) {
    printf("%d\n", add(3, 5)); // 8
    return 0;
}
```

头文件保护：#ifndef / #define / #endif 防止同一翻译单元内重复展开头文件内容。

## 复习重点

优先掌握：static 局部变量的行为、函数指针的声明、int *p[3] 与 int (*p)[3] 的区别、#ifdef 与 #if 的区别、.h 声明与 .c 实现的分工。
