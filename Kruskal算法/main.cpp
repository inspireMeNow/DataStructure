#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int arr[100001];
int sizes[100001];
void init(int n){
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=1;i<=n;i++){
        sizes[i]=1;
    }
}
int find(int i){ //找祖先
    while(arr[i]!=i){
        i=arr[i];
    }
    return i;
}
bool connect(int i,int j){
    int a=find(i),b=find(j);
    if(a==b){
        return 0;
    }
    if(sizes[a]>sizes[b]){
        sizes[a]+=sizes[b];
        arr[b]=a;
    }
    else{
        sizes[b]+=sizes[a];
        arr[a]=b;
    }
    return 1;
}
int main(){
    int m,n;
    cout<<"请输入顶点数和边数：";
    cin>>n>>m;
    init(n);
    vector<int> vector(n);
    std::vector<std::vector<int>>road(m,std::vector<int>(3));
    cout<<"请输入两个顶点和各组成边的值："<<endl;
    for(int i=0;i<m;i++){
        cin>>road[i][0]>>road[i][1]>>road[i][2];
    }
    int total=0;
    auto comp=[](std::vector<int> a,std::vector<int> b)->bool{
        return a[2]<b[2];
    };
    sort(road.begin(),road.end(),comp);
    cout<<"各组成边长度分别为：";
    for(int i=0,count=1;i<m&&count<n;i++){
        if(connect(road[i][0],road[i][1])){
            total=total+road[i][2];
            cout<<road[i][2]<<" ";
            count++;
        }
    }
    cout<<"最小生成树的权值为："<<total<<endl;
}
