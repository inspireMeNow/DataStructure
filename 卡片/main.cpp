#include <iostream>
using namespace std;
int main()
{
  int arr[10];
  for(int i=0;i<10;i++){
    arr[i]=2021;
  }
  int i;
  int n;
  int flag=0;
  for(i=1;;i++){
    n=i;
    while(n){
      if(arr[n%10]>0)arr[n%10]--;
      else{
        flag=1;
        break;
      }
      //cout<<n%10<<" ";
      n=n/10;
    }
    if(flag==1)break;
  }
  i=i-1;
  cout<<i<<endl;
  return 0;
}