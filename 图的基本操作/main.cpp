# include <iostream>
# include <stdlib.h>
# include <cstring>
# include <iomanip>
# include "MGraph.h"
using namespace std;
int visited[30];
#define MAX_VER_TEX 30
typedef string ResultCode;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    int weight;
}ArcNode;
typedef struct vertexNode{
    int data;
    ArcNode *firstarc;
}vertexNode;
typedef struct{
    vertexNode vertex[30];
    int arcnum;
    int vexnum;
}AdjList;
int create(AdjList *a)
{
	int i,j,n;
	int sum;//sum和arcnum一样代表图中总的边数 
	ArcNode *p1,*p2,c;
	printf("请输入图顶点的总个数和边的总个数\n");
	scanf("%d %d",&a->vexnum,&a->arcnum);
	sum=a->arcnum; 
	for(i=0;i<a->vexnum;i++)
    	a->vertex[i].firstarc=NULL;//初始化和顶点第一个相邻的边为空; 
	for(i=0;i<a->vexnum;i++)
	{
	 	
	printf("请输入第%d个顶点的值\n",i);
	scanf("%d",&a->vertex[i].data);
	 if(sum==0) continue;
	printf("请输入和本顶点相关边的个数\n");
	scanf("%d",&n); 
	 
	for(j=0;j<n;j++)
	{
		if(j==0)
		{

		  int q;
			p1=p2=( ArcNode*)malloc(sizeof(ArcNode));
			//p1=p2=&c;
			p1->next=p2->next=NULL;
			a->vertex[i].firstarc=p1;
			printf("请输入与第%d个顶点,第%d个相邻的边顶点(位置) 以及边的权值\n",i,j);
			scanf("%d %d",&p1->adjvex,&p1->weight);
			//printf("%d %d",p1->adjvex,p2->weigh);	
			sum--;		 			 
		}
		else{
			p2=(ArcNode*)malloc(sizeof(ArcNode));
			p2->next=NULL;
			p1->next=p2;
			printf("请输入第%d个顶点,第%d个相邻的边顶点 以及两个顶点间边的权值\n",i,j);
			scanf("%d %d",&p2->adjvex,&p2->weight);	
			sum--;		
		}
		
	}
	printf("\n");
	}
}
void Print(AdjList a){
    int i,j;
    for(i=0;i<a.vexnum;i++){
    ArcNode *p;
    p=a.vertex[i].firstarc;
    cout<<a.vertex[i].data<<" ";
    while(p){
        cout<<"->";
        cout<<p->adjvex<<" "<<p->weight;
        p=p->next;
    }
    cout<<endl;
    }
}
int  DepthFirstSearch(AdjList a,int i){
	ArcNode *p;
	printf(" %d",a.vertex[i].data);
	visited[i]=1;
	p=a.vertex[i].firstarc;
	while(p)
	{
		if(!visited[p->adjvex])
		DepthFirstSearch(a,p->adjvex); 
		p=p->next; 
	}
}
void traverseGraph(AdjList a){
     int i,j;
     for(i=0;i<a.vexnum;i++)
     visited[i]=0;
	 for(i=0;i<a.vexnum;i++){
	 	if(!visited[i]) 
	 	DepthFirstSearch(a,i); 
	 } 	
}
int Locate(AdjList g,int16_t elem)//定位这个结点在数组中的位置
{
    	int i;
	for(i=0;i<g.vexnum;i++)
	{
    	if(elem==g.vertex[i].data)
		return i; 
	}
	return -1;//找不到对应元素，返回-1表示不存在 
}
int InsertArc(AdjList *g,int a,int b,int aweight)
{
    	int pa,pb;
	    ArcNode*p;
		pa=Locate(*g,a);//起点在数组里的位置 
		pb=Locate(*g,b);//终点在数组里的位置
		if(pa<0||pb<0)
		{
    	printf("这个边并不存在，请重新输入\n");
			return -1;
		}
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=pb;
		p->weight=aweight;
		//下面把这个边信息插到起点的边信息的第一个 
		p->next=g->vertex[pa].firstarc;
		g->vertex[pa].firstarc=p;
		g->arcnum++;//边个数增加 
		return 0;
}
int DeleteArc(AdjList *g,int i,int j)
{
	int k;
	ArcNode *p,*pre,*del;//del为被删除结点，pre为del前驱
	for(p=g->vertex[i].firstarc;;p=p->next)
	{
		pre=p;
		if(p==NULL)//没有弧
		{
			printf("不存在弧<v%d,v%d>,删除弧失败！\n",i,j);
			return -1;
		}
		if(p->adjvex==j)
		{
			if(p==g->vertex[i].firstarc)	//被删除弧结点为第一个结点
			{
				del=p;
				p=p->next;
				g->vertex[i].firstarc=p;
				delete del;	//删除弧结点
				pre=NULL;
	
				g->arcnum--;	//弧数量减一
				return 0;
			}
			else		//被删除弧结点不是第一个结点
			{
				del=p;
				p=p->next;
				pre->next=p;
				delete del;	//删除弧结点
	
				g->arcnum--;	//弧数量减一
				return 0;
			}
		}
	}
	return 0;
}
int InsertVex(AdjList *g,int adata)
{
    	int i;
	if(g->vexnum==MAX_VER_TEX)
	return -1;
	for(i=0;i<g->vexnum;i++)
	{
    	if(adata==g->vertex[i].data)
		return -1;
	}
	g->vertex[g->vexnum].data=adata;
	g->vertex[g->vexnum].firstarc=NULL;
	g->vexnum++;//顶点个数增加 
	return g->vexnum-1;
}
int Delete(ArcNode *p)//删除顶点的辅助函数：递归调用删除边结点内容 
{
    	if(p)
	{
    
		Delete(p->next);
		delete p;
		return 0;
	}
	else 
		return NULL;
}
int DeleteVex(AdjList *g,int adata)
{
    int qq=0;
	ArcNode *p,*del,*pre;
	int pdata=Locate(*g,adata);//定位结点位置 
	if(pdata<0)//结点不存在，返回错误信息 
	return -1;
	//Delete(g->vertex[pdata].firstarc);//删除这个结点储存的边信息
	p=g->vertex[pdata].firstarc;
	while(p)
	{
    	g->arcnum--;
		p=p->next;
	 } 
	int i;
	for(i=pdata;i<g->vexnum-1;i++)//数组内容移位 
	{
    	g->vertex[i].data=g->vertex[i+1].data;
		g->vertex[i].firstarc=g->vertex[i+1].firstarc;//顶点信息和第一条边的指针都移位 
	}
	g->vertex[g->vexnum-1].data=-1;
	g->vertex[g->vexnum-1].firstarc=NULL;
	g->vexnum--;//顶点个数减1 
	for(i=0;i<g->vexnum;i++)
	{
    	p=g->vertex[i].firstarc;
		while(p)
		{
    	if(p->adjvex==pdata)
			{
    	
				if(p==g->vertex[i].firstarc)
				{
    	del=p;
					p=p->next;
					g->vertex[i].firstarc=p;
					pre=NULL;
					free(del);
					g->arcnum--;
					break;
				}
				else
				{
    	del=p;
					p=p->next;
					pre->next=p;
					free(del);
					g->arcnum--;
					break;
				}
			}
			else if(p->adjvex>pdata)
			{
    	p->adjvex--;
			}
			pre=p;
			p=p->next;
		}
		
	}
	return 0; 
}
void ShortestPath_DIJ(AdjList &G,int v0)
{
    int n = G.vexnum,k;
    bool S[n] = {false};
    int D[n],Min;
    int Path[n];

    ArcNode* p;
    //初始化最短路径的值
    for(int v=0;v<n;++v)
        D[v] = 10000;
    p = G.vertex[v0].firstarc;
    //将与v0相关联的边的权值赋给D[]
    while(p != NULL)
    {
        D[p->adjvex] =p->weight ;
        p = p->next;
    }
    S[v0] = true;       //将v0加入终点集
    Path[0] = v0;       //记录最短路径
    D[v0] = 0;
    for(int v=1;v<n;++v)
    {
        Min = 10000;
        //寻找最小值
        for(int w=0;w<n;++w)
        {
            if(!S[w] && D[w]<Min)
            {
                k = w;
                Min = D[w];
            }
        }
        S[k] = true;
        Path[v] = k;
        p = G.vertex[k].firstarc;
        while(p != NULL)
        {
            if(!S[p->adjvex] && D[k]+p->weight<D[p->adjvex])
                D[p->adjvex] = D[k]+p->weight;
            p = p->next;
        }
    }
    for(int i=1;i<n;i++)
    {
        cout << "终点集为：";
        for(int j=0;j<=i;j++)
            cout << G.vertex[Path[j]].data;
        cout << setw(15) << "最短路径值为:" << D[Path[i]] << endl;
    }
}
int main(){
    AdjList a;
	int i=1;
	int j;
    create(&a);
    Print(a);cout<<"深度遍历图为："<<endl;traverseGraph(a);ShortestPath_DIJ(a,i);
	int x;
	cout<<"请输入要插入的顶点的值："<<endl;
	
	for(;;){
	cin>>x;
	j=InsertVex(&a,x);
	if(j==-1)
		cout<<"输入错误，请重新输入"<<endl;
	else break;
	}
	Print(a);cout<<"深度遍历图为："<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
	int d,b,c;
	cout<<"请输入顶点,相邻的边顶点(位置) 以及边的权值"<<endl;
	for(;;){
	cin>>d>>b>>c;
	j=InsertArc(&a,d,b,c);
	if(!j)break;
	}
    Print(a);cout<<"深度遍历图为："<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
	int e;
	cout<<"请输入要删除的顶点的值："<<endl;
	for(;;){
	cin>>e;
	j=DeleteVex(&a,e);
	if(j==-1)
		cout<<"输入错误，请重新输入"<<endl;
	else break;
	}
	Print(a);cout<<"深度遍历图为："<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
	cout<<"请输入要删除的顶点,相邻的边顶点(位置) 以及边的权值"<<endl;
	for(;;){
	cin>>d>>b;
	j=DeleteArc(&a,d,b);
	if(j==-1)
		cout<<"输入错误，请重新输入"<<endl;
	else break;
	}
    Print(a);cout<<"深度遍历图为："<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
    system("pause");
    return 0;
}