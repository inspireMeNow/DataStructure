# include "Data.h"
# include "Stack.h"
# include "SeqQueue.h"
int main(){
    SeqQueue a;
    int n;
    cout<<"请输入可以停放车辆的个数：";
    cin>>n;
    Stack b1(n),b2(n);
    cout<<"请输入所有数据：";
    int num;
    cin>>num;
    char c,status;
    int number,time;
    Data *data[num];
    for(int i=0;i<num;i++){
    cin>>c>>c>>status>>c>>c>>number>>c>>time>>c;
    data[i]=new Data(status,number,time);
    }
    return 0;
}