# include "Data.h"
class Node{
   public:
   Data data;
   struct Node *next;
   Node(Data e):data(e),next(NULL){}
   Node(){}
};