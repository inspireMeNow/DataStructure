# include <iostream>
using namespace std;
# define maxn 100
typedef struct{
    int weight;
    int parent,lchild,rchild;
}Node;
class Tree{
    const int n=maxn;
    int m;
    typedef char *HuffmanCode;
    public:
    Node *CreateHuffmanTree(int n){
    if(n<=1)exit(0);
    m=2*n-1;
    Node *t=new Node[m+1];
    for(int i=1;i<=m;i++){
        t[i].parent=0;
        t[i].lchild=0;
        t[i].rchild=0;
    }
    for(int i=1;i<=n;i++){
        cin>>t[i].weight;
    }
    int s1,s2;
    for(int i=n+1;i<=m;i++){
        //Select(T,i-1,s1,s2);
        t[s1].parent=i;
        t[s2].parent=i;
        t[i].lchild=s1;
        t[i].rchild=s2;
        t[i].weight=t[s1].weight+t[s2].weight;
    }
    return t;
    }
    void CreateHuffmanCode(Node t,HuffmanCode c,int n){

    }
};
class Data{
    float weight;
    char data;

};
int main(){
    return 0;
}