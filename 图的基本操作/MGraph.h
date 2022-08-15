# include <iostream>
using namespace std;
typedef string ResultCode;
class MGraph{
public:
MGraph(int size,const int noedg){
n=size;
e=0;
noEdge=noedg;
a=new int *[n];
for(int i=0;i<n;i++){
    a[i]=new int[n];
    for(int j=0;j<n;j++){
        a[i][j]=noEdge;
    }
    a[i][i]=0;
}
}
~MGraph(){
for(int i=0;i<n;i++){
    delete []a[i];
}
delete []a;
}
bool Exist(int u,int v) const{
if(u<0||u>n-1||v<0||v>n-1||u==v)
       return 0;
else   return 1;
}
ResultCode Insert(int u,int v,int w){
if(u<0||u>n-1||v<0||v>n-1||u==v)
       return "Failure";
    if(a[u][v]!=noEdge)return "Duplicate";
    a[u][v]=w;
    e++;
    return "Success";
}
ResultCode Remove(int u,int v){
if(u<0||u>n-1||v<0||v>n-1||u==v)
       return "Failure";
       a[u][v]=0;
       return "Success";
}
private:
int **a;
int noEdge;
int n;
int e;
};
