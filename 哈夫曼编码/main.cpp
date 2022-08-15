# include <iostream>
# include <cstring>
# include <stdlib.h>
using namespace std;
# define maxn 100
char N[1000];
typedef struct{
    int weight;
    int parent,lchild,rchild;
}Node;
typedef  struct 
{
    int s1;
    int s2;
}MinCode;
typedef char **HuffmanCode;
class Tree{
    const int n=maxn;
    int m;
    public:
    MinCode Select(Node *HT,int n)//选择最小结点
{  
    int min,secmin;
    int temp = 0;
    int i,s1,s2,tempi = 0;
    MinCode  code ;
    s1=1;
    s2=1;
    min = 66666;
    for(i=1;i<=n;i++)
    {
        if(HT[i].weight<min && HT[i].parent==0)
        {
            min=HT[i].weight;
            s1=i;
        }
    }
    secmin=999999;//足够大
    for(i=1;i<=n;i++)
    {
        if((HT[i].weight<secmin) && (i!=s1) && HT[i].parent==0)
        {
            secmin=HT[i].weight; 
            s2=i;
        }
    }
    code.s1=s1;
    code.s2=s2;
    return code;
}
    Node *CreateHuffmanTree(Node *t,HuffmanCode &hc,int n){//构造哈夫曼树
    if(n<=1)exit(0);
    m=2*n-1;
    t=new Node[m+1];
    int i;
    //HuffmanCode hc;
    for(int i=1;i<=m;i++){
        t[i].parent=0;
        t[i].lchild=0;
        t[i].rchild=0;
    }
    for(int i=1;i<=n;i++){
        cin>>t[i].weight;
    }
    int s1,s2;
    for(i=n+1;i<=m;i++){
        MinCode min;
        min=Select(t,i-1);
        s1=min.s1;
        s2=min.s2;
        t[s1].parent=i;
        t[s2].parent=i;
        t[i].lchild=s1;
        t[i].rchild=s2;
        t[i].weight=t[s1].weight+t[s2].weight;
    }
     printf("HT  List:\n");
    printf("Number\t\tweight\t\tparent\t\tlchild\t\trchild\n");

    for(i=1;i<=m;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\n",i,t[i].weight,t[i].parent,t[i].lchild,t[i].rchild);
    }
        hc=(HuffmanCode)malloc((n+1)*sizeof(char *));
        char *cd=new char[n];
        cd[n-1]='\0';
        int c,f,start,m;
        for(i=1;i<=n;i++){ 
        start=n-1;
        //定义左子树为0，右子树为1
        for(c=i,f=t[i].parent; f!=0; c=f,f=t[f].parent)
        {
            if(t[f].lchild==c)  
                cd[--start]='0';
            else 
                cd[--start]='1';
        }

        //为第i个字符分配编码空间
        hc[i]=new char(n-start);
        //将当前求出结点的哈弗曼编码复制到HC
        strcpy(hc[i],&cd[start]);
    }
    free(cd);
    return t;
    }
    void HuffmanTranslateCoding(Node *HT,int n,char* ch)
{//译码过程
    int m=2*n-1;
    int i,j=0;

    printf("After Translation:");
    while(ch[j]!='\0')
    {
        i=m;
        while(0 != HT[i].lchild && 0 != HT[i].rchild)//从顶部找到最下面
        {
            if('0' == ch[j])//往左子树走
            {
                i=HT[i].lchild;
            }
            else//往右子树走
            {
                i=HT[i].rchild;
            }
            ++j;//下一个路径
        }
        printf("%c",N[i-1]);//打印出来
    }
    printf("\n");
}
};
int main(){
    int i;
    Node *HT=NULL;
    HuffmanCode HC=NULL;
    Tree a;
    cin>>N;
    int n=strlen(N);
    HT=a.CreateHuffmanTree(HT,HC,n);
        //输出哈弗曼编码
    printf("HuffmanCode:\n");
    printf("Number\t\n");
        for(i=1;i<=n;i++)
    {
        printf("%c\t\t%d\t\t%s\n",N[i-1],HT[i].weight,HC[i]);
    }
    fflush(stdin);
    //译码过程
    printf("Input HuffmanTranslateCoding:");
    char trans[100];
    cin>>trans;
    a.HuffmanTranslateCoding(HT,n,trans);
    system("pause");
    return 0;
}