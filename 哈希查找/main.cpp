#include <iostream>
using namespace std;
int hash1(int value,int n){
    return value%n;
}
void createHash(int arr[],int hashArr[],int m,int n){
    int i,index;
    for(i=0;i<n;i++){
        index=hash1(arr[i],m);
        while(hashArr[index%m]!=0){
            index++;
        }
        hashArr[index]=arr[i];
    }
}
int hash_search(int *hashArr,int value,int n){
    int hashAdd=hash1(value,n);
    if(hashArr[hashAdd]!=value){
        cout<<"发生冲突，依次向后探测！"<<endl;
    }
    while(hashArr[hashAdd]!=value){
        hashAdd=(hashAdd+1)%n;
        if(hashArr[hashAdd]==0||hashAdd==hash1(value,n)){
            return -1;
        }
    }
    return hashAdd;
}
int main() {
    int m,n;
    cout<<"请输入序列的长度和哈希表的长度：";
    cin>>n>>m;
    int arr[n];
    cout<<"请输入序列：";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int hashAdd;
    int hashArr[m];
    for(int i=0;i<m;i++){
        hashArr[i]=0;
    }
    createHash(arr,hashArr,m,n);
    cout<<"哈希表为：";
    for(int i=0;i<m;i++){
        cout<<hashArr[i]<<" ";
    }
    cout<<endl;
    cout<<"请输入要查找的数字：";
    int num;
    cin>>num;
    hashAdd= hash_search(hashArr,num,m);
    if(hashAdd==-1){
        cout<<"查找失败！"<<endl;
    }
    else{
        cout<<"查找成功，元素所在下标为："<<hashAdd<<endl;
    }
    return 0;
}
