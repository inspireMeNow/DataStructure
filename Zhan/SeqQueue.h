# include "Data.h"
# include "Node.h"
class SeqQueue{
   public:
   Node *phead=NULL;
   Node *pend=NULL;
   int count;
   SeqQueue():phead(NULL),pend(NULL),count(0){
   phead=new Node();
   pend=phead;
   count=0;
   }
   void Push(Data e){
   Node *pnode=new Node(e);
   pend->next=pnode;
   pend=pnode;
   count++;
   }
   bool Pop(){
   if(count==0){
       return 0;
   }
   else{
       Node *pnode=phead->next;
       phead->next=phead->next->next;
       delete pnode;
       count--;
       return 1;
   }
   }
   void Print(){
   while(!IsEmpty()){
   //cout<<front()<<endl;
   }
   }
   Data front(){
       return phead->next->data;
   }
bool IsEmpty(){
    return count==0;
}
int size(){
    return count;
}
};