# include <iostream>
using namespace std;
typedef struct LNode{
    int id;
    int data;
    struct LNode *next;
}LNode;
LNode *LinkList;
void CreateList(int a[],int n){
    LNode *L=new LNode;
    for(int i=0;i<n;i++){
        cin>>a[i];
        L->id=i+1;
        L->data=a[i];
        if(i==0)LinkList=L;
        L->next=new LNode;
        if(i==n-1){
            L->next=LinkList;
        }
        L=L->next;
    }
}
void PrintCode(LNode *l,int j,int n){
    l=LinkList;
    LNode *l1;
    if(j>n)j=j%n;
    while(n--){
        if(n==0){
            cout<<l->id<<" ";
            break;
        }
        if(j!=-1){
            for(int i=1;i<=j-2;i++){
            l=l->next;
            }
        }
        else{
            int l2=l->id;
            for(;;){
               l=l->next;
               if(l->next->id==l2)break; 
            }
        }
        cout<<l->next->id<<" ";
        j=l->next->data;
        if(j>n)j=j%n;
        l1=l->next;
        l->next=l->next->next;
        l=l->next;
        delete l1;
    }
}
int main(){
    LNode *l;
    int n;
    int m;
    int a[30];
    cout<<"请输入人数:"<<endl;
    cin>>n;
    cout<<"请输入密码初值："<<endl;
    cin>>m;
    CreateList(a,n);
    l=LinkList;
    PrintCode(l,m,n);
    system("pause");
    return 0;
}