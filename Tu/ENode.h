class ENode{
  public:
  ENode *nextArc;
  ENode *firstArc;
  int weight;
  int adjVex;
  ENode(int v,int w,ENode *n){
  adjVex=v;
  weight=w;
  nextArc=n;
  }
};