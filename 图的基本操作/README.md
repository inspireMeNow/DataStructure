# 实验内容

分别用邻接矩阵和邻接表实现以下操作：图的创建、遍历、插入、删除、最短路径

# 设计文档
```c++

//邻接表

int visited[30];

 #define MAX_VER_TEX 30

typedef string ResultCode;

typedef struct ArcNode{

int adjvex;

struct ArcNode  *next;//下一结点

int weight;//权值

}ArcNode;

typedef struct vertexNode{

int data;//数据

ArcNode  *firstarc;//第一个结点

}vertexNode;

typedef struct{

vertexNode vertex[30];

int arcnum;//边的数目

int vexnum; //结点数目

}AdjList;//数据结构

//邻接矩阵

typedef string ResultCode;

class MGraph{

private:

int  * *a;//矩阵

int noEdge;//赋值用

int n;//元素个数

int e;

public:

MGraph(int size,const int noedg); //初始化邻接矩阵

 ~MGraph(); //释放矩阵空间

bool Exist(int u,int v) const; //元素存在

ResultCode Insert(int u,int v,int w); //插入元素

ResultCode Remove(int u,int v); //删除元素

};

int create(AdjList  *a);//创建邻接表

void Print(AdjList a); //打印邻接表

int DepthFirstSearch(AdjList a,int i); //深度搜索

void traverseGraph(AdjList a); //深度遍历图

int Locate(AdjList g,int16_t elem); //定位结点位置

int InsertArc(AdjList  *g,int a,int b,int aweight); //输入边和它的权值

int DeleteArc(AdjList  *g,int i,int j);//删除边

int InsertVex(AdjList  *g,int adata); //插入结点

int Delete(ArcNode  *p); //删除顶点的辅助函数：递归调用删除边结点内容

int DeleteVex(AdjList  *g,int adata); //删除结点

void ShortestPath_DIJ(AdjList  &G,int v0); //求最短路径
```
# 程序运行结果

请输入图顶点的总个数和边的总个数

3 2

请输入第0个顶点的值

0

请输入和本顶点相关边的个数

2

请输入与第0个顶点,第0个相邻的边顶点(位置) 以及边的权值

1 999

请输入第0个顶点,第1个相邻的边顶点 以及两个顶点间边的权值

2 999

请输入第1个顶点的值

1

请输入第2个顶点的值

2

0 -\>1 999-\>2 999

1

2

深度遍历图为：

0 1 2终点集为：12 最短路径值为:10000

终点集为：122 最短路径值为:10000

请输入要插入的顶点的值：

3

0 -\>1 999-\>2 999

1

2

3

深度遍历图为：

0 1 2 3终点集为：01 最短路径值为:999

终点集为：012 最短路径值为:999

终点集为：0122 最短路径值为:999

请输入顶点,相邻的边顶点(位置) 以及边的权值

1 2 5

0 -\>1 999-\>2 999

1 -\>2 5

2

3

深度遍历图为：

0 1 2 3终点集为：01 最短路径值为:999

终点集为：012 最短路径值为:999

终点集为：0122 最短路径值为:999

请输入要删除的顶点的值：

3

0 -\>1 999-\>2 999

1 -\>2 5

2

深度遍历图为：

0 1 2终点集为：01 最短路径值为:999

终点集为：012 最短路径值为:999

请输入要删除的顶点,相邻的边顶点(位置) 以及边的权值

1 2

0 -\>1 999-\>2 999

1

2

深度遍历图为：

0 1 2终点集为：01 最短路径值为:999

终点集为：012 最短路径值为:999