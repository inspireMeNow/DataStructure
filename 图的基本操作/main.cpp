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
	int sum;//sum��arcnumһ������ͼ���ܵı��� 
	ArcNode *p1,*p2,c;
	printf("������ͼ������ܸ����ͱߵ��ܸ���\n");
	scanf("%d %d",&a->vexnum,&a->arcnum);
	sum=a->arcnum; 
	for(i=0;i<a->vexnum;i++)
    	a->vertex[i].firstarc=NULL;//��ʼ���Ͷ����һ�����ڵı�Ϊ��; 
	for(i=0;i<a->vexnum;i++)
	{
	 	
	printf("�������%d�������ֵ\n",i);
	scanf("%d",&a->vertex[i].data);
	 if(sum==0) continue;
	printf("������ͱ�������رߵĸ���\n");
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
			printf("���������%d������,��%d�����ڵı߶���(λ��) �Լ��ߵ�Ȩֵ\n",i,j);
			scanf("%d %d",&p1->adjvex,&p1->weight);
			//printf("%d %d",p1->adjvex,p2->weigh);	
			sum--;		 			 
		}
		else{
			p2=(ArcNode*)malloc(sizeof(ArcNode));
			p2->next=NULL;
			p1->next=p2;
			printf("�������%d������,��%d�����ڵı߶��� �Լ����������ߵ�Ȩֵ\n",i,j);
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
int Locate(AdjList g,int16_t elem)//��λ�������������е�λ��
{
    	int i;
	for(i=0;i<g.vexnum;i++)
	{
    	if(elem==g.vertex[i].data)
		return i; 
	}
	return -1;//�Ҳ�����ӦԪ�أ�����-1��ʾ������ 
}
int InsertArc(AdjList *g,int a,int b,int aweight)
{
    	int pa,pb;
	    ArcNode*p;
		pa=Locate(*g,a);//������������λ�� 
		pb=Locate(*g,b);//�յ����������λ��
		if(pa<0||pb<0)
		{
    	printf("����߲������ڣ�����������\n");
			return -1;
		}
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=pb;
		p->weight=aweight;
		//������������Ϣ�嵽���ı���Ϣ�ĵ�һ�� 
		p->next=g->vertex[pa].firstarc;
		g->vertex[pa].firstarc=p;
		g->arcnum++;//�߸������� 
		return 0;
}
int DeleteArc(AdjList *g,int i,int j)
{
	int k;
	ArcNode *p,*pre,*del;//delΪ��ɾ����㣬preΪdelǰ��
	for(p=g->vertex[i].firstarc;;p=p->next)
	{
		pre=p;
		if(p==NULL)//û�л�
		{
			printf("�����ڻ�<v%d,v%d>,ɾ����ʧ�ܣ�\n",i,j);
			return -1;
		}
		if(p->adjvex==j)
		{
			if(p==g->vertex[i].firstarc)	//��ɾ�������Ϊ��һ�����
			{
				del=p;
				p=p->next;
				g->vertex[i].firstarc=p;
				delete del;	//ɾ�������
				pre=NULL;
	
				g->arcnum--;	//��������һ
				return 0;
			}
			else		//��ɾ������㲻�ǵ�һ�����
			{
				del=p;
				p=p->next;
				pre->next=p;
				delete del;	//ɾ�������
	
				g->arcnum--;	//��������һ
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
	g->vexnum++;//����������� 
	return g->vexnum-1;
}
int Delete(ArcNode *p)//ɾ������ĸ����������ݹ����ɾ���߽������ 
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
	int pdata=Locate(*g,adata);//��λ���λ�� 
	if(pdata<0)//��㲻���ڣ����ش�����Ϣ 
	return -1;
	//Delete(g->vertex[pdata].firstarc);//ɾ�������㴢��ı���Ϣ
	p=g->vertex[pdata].firstarc;
	while(p)
	{
    	g->arcnum--;
		p=p->next;
	 } 
	int i;
	for(i=pdata;i<g->vexnum-1;i++)//����������λ 
	{
    	g->vertex[i].data=g->vertex[i+1].data;
		g->vertex[i].firstarc=g->vertex[i+1].firstarc;//������Ϣ�͵�һ���ߵ�ָ�붼��λ 
	}
	g->vertex[g->vexnum-1].data=-1;
	g->vertex[g->vexnum-1].firstarc=NULL;
	g->vexnum--;//���������1 
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
    //��ʼ�����·����ֵ
    for(int v=0;v<n;++v)
        D[v] = 10000;
    p = G.vertex[v0].firstarc;
    //����v0������ıߵ�Ȩֵ����D[]
    while(p != NULL)
    {
        D[p->adjvex] =p->weight ;
        p = p->next;
    }
    S[v0] = true;       //��v0�����յ㼯
    Path[0] = v0;       //��¼���·��
    D[v0] = 0;
    for(int v=1;v<n;++v)
    {
        Min = 10000;
        //Ѱ����Сֵ
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
        cout << "�յ㼯Ϊ��";
        for(int j=0;j<=i;j++)
            cout << G.vertex[Path[j]].data;
        cout << setw(15) << "���·��ֵΪ:" << D[Path[i]] << endl;
    }
}
int main(){
    AdjList a;
	int i=1;
	int j;
    create(&a);
    Print(a);cout<<"��ȱ���ͼΪ��"<<endl;traverseGraph(a);ShortestPath_DIJ(a,i);
	int x;
	cout<<"������Ҫ����Ķ����ֵ��"<<endl;
	
	for(;;){
	cin>>x;
	j=InsertVex(&a,x);
	if(j==-1)
		cout<<"�����������������"<<endl;
	else break;
	}
	Print(a);cout<<"��ȱ���ͼΪ��"<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
	int d,b,c;
	cout<<"�����붥��,���ڵı߶���(λ��) �Լ��ߵ�Ȩֵ"<<endl;
	for(;;){
	cin>>d>>b>>c;
	j=InsertArc(&a,d,b,c);
	if(!j)break;
	}
    Print(a);cout<<"��ȱ���ͼΪ��"<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
	int e;
	cout<<"������Ҫɾ���Ķ����ֵ��"<<endl;
	for(;;){
	cin>>e;
	j=DeleteVex(&a,e);
	if(j==-1)
		cout<<"�����������������"<<endl;
	else break;
	}
	Print(a);cout<<"��ȱ���ͼΪ��"<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
	cout<<"������Ҫɾ���Ķ���,���ڵı߶���(λ��) �Լ��ߵ�Ȩֵ"<<endl;
	for(;;){
	cin>>d>>b;
	j=DeleteArc(&a,d,b);
	if(j==-1)
		cout<<"�����������������"<<endl;
	else break;
	}
    Print(a);cout<<"��ȱ���ͼΪ��"<<endl;traverseGraph(a);ShortestPath_DIJ(a,i-1);
    system("pause");
    return 0;
}