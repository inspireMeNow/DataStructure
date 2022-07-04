# include "Data.h"
class Stack{
    int top;
    int maxsize;
    Data *s;
    public:
   Stack(int n){
       maxsize=n;
       Data *s=new Data[maxsize];
       top=-1;
   }
   ~Stack(){}
   void Push(Data x){
   if(IsFull()){
       cout<<"the stack is full!"<<endl;
       return;
   }
   s[++top]=x;
   }
   void Pull(){
   if(IsEmpty()){
       cout<<"error!"<<endl;
       return;
   }
   cout<<s[top-1]<<endl;
   }
   bool IsFull(){
   return (top==maxsize-1);
   }
   bool IsEmpty(){
   return (top==-1);
   }
   int getSize(){
       return maxsize;
   }   
};