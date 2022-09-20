# 实验内容

停车场管理

设停车场内只有一个的停放 n 辆汽车的狭长通道，且只有一个大门可供汽车进出。汽车 在停车场内按车辆到达时间的先后顺序，依次由北向南排列（大门在最南端，最先到达的第 一辆车停放在车场的最北端），若车场内已停满 n 辆汽车，则后来的汽车只能在门外的便道 上等候，一旦有车开走，则排在便道上的第一辆车即可开入；当停车场内某辆车要离开时， 在它之后开入的车辆必须先退出车场为它让路，待该辆车开出大门外，其它车辆再按原次序 进入车场，每辆停放在车场的车在它离开停车场时必须按它停留的时间长短交纳费用。试为 停车场编制按上述要求进行管理的模拟程序。

# 设计文档

```c++
typedef struct stackstruct{

int id;//汽车编号

int time;//停放时间

stackstruct *pre;//前结点

stackstruct *next;//后结点

};

typedef struct queuestruct{

int id;

queuestruct *next;//指向下一结点的指针

};

stackstruct *shead1,*send1;

stackstruct *shead2,*send2;

queuestruct  *qhead, *qend;//队列的前结点，后结点

int s1count,s2count;//元素下标

int qcount;//数据结构

void push(int flag,stackstruct  *p); //进栈

stackstruct  *pop(int id,int time); //出栈

struct stackstruct  *pop1(); //出栈

void Enqueue(struct stackstruct  *p); //入队，模拟便道

struct stackstruct  *Dequeue(int time); //出队
```