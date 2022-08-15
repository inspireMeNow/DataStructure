#include <iostream>
using namespace std;
template<typename T>
void Print(T array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
template<typename T>
void shell_sort(T array[],int length,int comp){
    int h=1;
    int k=1;
    while(h<length/3){
        h=3*h+1;
    }
    while(h>=1){
        for(int i=h;i<length;i++){
            if(comp==1){
                for(int j=i;j>=h&&array[j]<array[j-h];j=j-h){
                    swap(array[j],array[j-h]);
                }
            }
            else{
                for(int j=i;j>=h&&array[j]>array[j-h];j=j-h){
                    swap(array[j],array[j-h]);
                }
            }
        }
        cout<<"第"<<k<<"步的步长为："<<h<<" ；排序情况：";
        Print(array,length);
        h=h/3;
        k++;
    }
}
int main() {
    int n;
    int array[n];
    cout<<"请输入序列的长度：";
    cin>>n;
    cout<<"请输入序列中的每个数字：";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int flag;
    cout<<"请选择排序方式：1.升序排列 2.降序排列"<<endl;
    cin>>flag;
    while(flag!=1&&flag!=2){
        cout<<"输入错误，请重新输入！"<<endl<<"请选择排序方式：1.升序排列 2.降序排列"<<endl;
        cin>>flag;
    }
    shell_sort(array,n,flag);
    cout<<"希尔排序后的序列为：";
    Print(array,n);
    return 0;
}
