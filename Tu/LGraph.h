# include "Graph.h"
# include "ENode.h"
class LGraph:public Graph{
  ENode **a;
  int n;
  int e;
  public:
  LGraph(int size){
   n=size;
   e=0;
   a=new ENode*[n];
   for(int i=0;i<n;i++)a[i]=nullptr;
  }
  ~LGraph(){
   ENode *p,*q;
   for(int i=0;i<n;i++){
   p=a[i];
   q=p;
   while(p){
       p=p->nextArc;
       delete q;
       q=p;
   }
   }
   delete []a;
  }
  bool Exist(int u,int v){
       if(u<0||u>n-1||v<0||v>n-1||u==v)
       return 0;
       ENode *p=a[u];
       while(p&&p->adjVex!=v)p=p->nextArc;
       if(!p)return 0;
       else return 1;
  }
  ResultCode Insert(int u,int v,int w){
       if(u<0||u>n-1||v<0||v>n-1||u==v)
       return "Failure";
       if(Exist(u,v))return "Duplicate";
       ENode *p=new ENode(v,w,a[u]);
       a[u]=p;
       e++;
       return "Success";
  }
  ResultCode Remove(int u,int v){
       if(u<0||u>n-1||v<0||v>n-1||u==v)
       return "Failure";
       ENode *p=a[u],*q=NULL;
       while(p&&p->adjVex!=v){
           q=p;
           p=p->nextArc;
       }
       if(!p)return "NotPresent";
       if(q)q->nextArc=p->nextArc;
       else a[u]=p->nextArc;
       delete p;
       e--;
       return "Success"; 
  }
  void DFS1(int v,int n){
       cout<<v;
       int visited[n];
       visited[v]=1;
       
  }
};