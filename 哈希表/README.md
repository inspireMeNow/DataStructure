# 实验内容

针对某个集体中人名设计一个哈希表，使得平均查找长度不超过R，并完成相应的建表和查表程序

# 设计文档
```c++

//数据结构

\# define R 30 //最大长度

\# define NULLKEY -32768

typedef struct {

int elem; //人名对应的编码

char pinyin[30]; //存放人名

}Name;

typedef struct {

Name \*elem;

int count;//计数

}HashTable;

int m=0;

//函数设计

int Hash(int k); //取余

void Insert(HashTable \*h,int k,char a[]);插入人名

int Init(HashTable \*h); //初始化哈希表

int Search(HashTable \*h,int k); //查找人名对应编码

void Result(HashTable \*h); //打印存放结果

int Convert(char \*f); //将人名转化为编码
```