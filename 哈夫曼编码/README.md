# 实验内容

哈夫曼编/译码器

利用哈夫曼编码进行通信可以大大提高信道利用率，这要求在发送端通过一个编码系统 对待传输预先编码，在接收端将传来的数据进行译码。对于双工通道，每端都需要一个完整 的编/译码系统。

# 设计文档
```c++
# define maxn 100

char N[1000];

typedef struct{

int weight;权值

int parent,lchild,rchild;//双亲结点，左孩子，右孩子

}Node;

typedef struct

{

int s1;

int s2;

}MinCode;//取最小

typedef char  * *HuffmanCode;//哈夫曼编码

MinCode Select(Node  *HT,int n);//选择最小结点

Node  *CreateHuffmanTree(Node  *t,HuffmanCode  &hc,int n);//构造哈夫曼树

void HuffmanTranslateCoding(Node  *HT,int n,char * ch);//译码过程
```