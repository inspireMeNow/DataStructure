# 实验内容

约瑟夫（Joeph）问题的一种描述是：编号为 1,2,…,n 的 n 个人按顺时针方向围坐一圈，

每人持有一个密码（正整数）。一开始任选一个正整数作为报数上限值 m，从第一个人开始

按顺时针方向自 1 开始顺序报数，报到 m 时停止报数。报 m 的人出列，将他的密码作为新的 m 值，从他在顺时针方向上的下一个人开始重新从 1 报数，如此下去，直至所有人全部出列为止。试设计一个程序求出出列顺序。

# 设计文档

```c++
typedef struct LNode{

int id; //编号

int data; //持有的密码

struct LNode  *next;//指向下一节点的指针

}LNode;//数据结构

LNode  *LinkList;

void CreateList(int a[],int n); //创建循环链表

void PrintCode(LNode  *l,int j,int n); //输出出列次序
```