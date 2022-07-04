# include <iostream>
using namespace std;
typedef string ResultCode;
class Graph{
int n,e;
public:
virtual void Create(int n)=0;
virtual bool Exist(int u,int v) const=0;
virtual ResultCode Insert(int u,int v,int w)=0;//边<u,v>，权值w
virtual ResultCode Remove(int u,int v)=0;
virtual int Vertices() const=0;//返回顶点数目 
};