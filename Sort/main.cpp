# include <iostream>
# define MAXSIZE 1000
using namespace std;
typedef struct{
    int key;
}Redtype;
typedef struct{
Redtype r[MAXSIZE+1];
int length;
}SqList;
int comp=0;
int swap=0;
void Random(SqList &l,int max,int min){
   for(int i=1;i<=l.length;i++){
       l.r[i].key=(rand()% (max-min+1))+ min;
   }
}
void Print(SqList &l){
   for(int i=1;i<=l.length;i++){
       cout<<l.r[i].key<<" ";
   }
   cout<<endl;
}
int Partition(SqList &L,int low,int high){
    L.r[0]=L.r[low];
    int pivotkey=L.r[low].key;
    ::swap++;
    while(low<high){
        while(low<high&&L.r[high].key>=pivotkey){--high;::comp++;}
        L.r[low]=L.r[high];
        ::swap++;
        while(low<high&&L.r[low].key<=pivotkey){++low;::comp++;}
        L.r[high]=L.r[low];
        ::swap++;
    }
    L.r[low]=L.r[0];
    ::swap++;
    return low;
}
void QSort(SqList &L,int low,int high){
    int pivotloc;
    if(low<high){
    pivotloc=Partition(L,low,high);
    QSort(L,low,pivotloc-1);
    QSort(L,pivotloc+1,high);
    }
}
SqList QuickSort(SqList &R){
SqList L;
L=R;
QSort(L,1,L.length);
return L;
}
SqList SelectSort(SqList &R){
SqList L;
L=R;
int i,j,k;
Redtype t;
for(i=1;i<L.length;i++){
    k=i;
    for(j=k+1;j<=L.length;j++){
        if(L.r[j].key<L.r[k].key){k=j;::comp++;}
    }
    if(k!=i){
    t=L.r[i];
    L.r[i]=L.r[k];
    L.r[k]=t;
    ::swap+=3;
    }
}
return L;
}
SqList BubbleSort(SqList &R){
   SqList L;
   L=R;
   bool flag=1;
   for(int i=1;flag&&i<=L.length-1;i++){
       flag=0;
       for(int j=1;j<=L.length-i;j++){
           if(L.r[j].key>L.r[j+1].key){
           ::comp++;
           Redtype temp=L.r[j];
           L.r[j]=L.r[j+1];
           L.r[j+1]=temp;
           ::swap+=3;
           flag=1;
           }
       }
   }
   return L;
}
SqList InsertSort(SqList &R){
   SqList L;
   L=R;
   int i,j;
   for(i=2;i<=L.length;++i){
       if(L.r[i].key<L.r[i-1].key){
           ::comp++;
           L.r[0]=L.r[i];
           L.r[i]=L.r[i-1];
           ::swap+=2;
           for(j=i-2;L.r[0].key<L.r[j].key;--j){
               L.r[j+1]=L.r[j];
               ::swap++;
               ::comp++;
           }
           L.r[j+1]=L.r[0];
           ::swap++;
       }
   }
   return L;
}
SqList ShellSort(SqList &R){
SqList L;
L=R;
int h=1;
while(h<L.length/3){
    h=3*h+1;
}
while(h>=1){
    for(int i=h+1;i<=L.length;i++){
        for(int j=i;j>=h&&L.r[j].key<L.r[j-h].key;j-=h){
        Redtype t=L.r[j];
        L.r[j]=L.r[j-h];
        L.r[j-h]=t;
        ::comp++;
        ::swap+=3;
        }
    }
    h=h/3;
}
return L;
}
void HeapAdjust(SqList &L,int s,int m){
    Redtype rc=L.r[s];
    for(int j=2*s;j<=m;j*=2){
        if(j<m&&L.r[j].key<L.r[j+1].key){++j;::comp++;}
        if(rc.key>=L.r[j].key){::comp++;break;}
        L.r[s]=L.r[j];
        ::swap++;
        s=j;
    }
    L.r[s]=rc;
    ::swap++;
}
void CreateHeap(SqList &L){
    int n=L.length;
    for(int i=n/2;i>0;--i){
        HeapAdjust(L,i,n);
    }
}
SqList HeapSort(SqList &R){
    SqList L;
    L=R;
    CreateHeap(L);
    for(int i=L.length;i>1;--i){
        Redtype x=L.r[1];
        L.r[1]=L.r[i];
        L.r[i]=x;
        ::swap+=3;
        HeapAdjust(L,1,i-1);
    }
    return L;
}
int main(){
    int n;
    cout<<"你想对几个数排序？"<<endl;
    cin>>n;
    SqList l,r;
    l.length=n;
    int max,min;
    cout<<"请输入随机数的范围："<<endl;
    cin>>max>>min;
    Random(l,max,min);
    r=InsertSort(l);
    cout<<"排序结果为："<<endl;
    Print(r);
    cout<<"直接插入排序的比较次数为："<<::comp<<"，移动次数为："<<::swap<<endl;
    ::comp=0;::swap=0;
    r=BubbleSort(l);
    Print(r);
    cout<<"起泡排序的比较次数为："<<::comp<<"，移动次数为："<<::swap<<endl;
    ::comp=0;::swap=0;
    r=SelectSort(l);
    Print(r);
    cout<<"简单选择排序的比较次数为："<<::comp<<"，移动次数为："<<::swap<<endl;
    ::comp=0;::swap=0;
    r=QuickSort(l);
    Print(r);
    cout<<"快速排序的比较次数为："<<::comp<<"，移动次数为："<<::swap<<endl;
    ::comp=0;::swap=0;
    r=ShellSort(l);
    Print(r);
    cout<<"希尔排序的比较次数为："<<::comp<<"，移动次数为："<<::swap<<endl;
    ::comp=0;::swap=0;
    r=HeapSort(l);
    Print(r);
    cout<<"堆排序的比较次数为："<<::comp<<"，移动次数为："<<::swap<<endl;
    return 0;
}
