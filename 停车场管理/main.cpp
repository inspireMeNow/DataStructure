# include <iostream>
# include <stdlib.h>
# include <cmath>
using namespace std;
typedef struct stackstruct{
int id;
int time;
stackstruct *pre;
stackstruct *next;
};
typedef struct queuestruct{
int id;
queuestruct *next;
};
stackstruct *shead1,*send1;
stackstruct *shead2,*send2;
queuestruct *qhead,*qend;
int s1count,s2count;
int qcount;
void push(int flag,stackstruct *p){
    stackstruct *next;
    if(flag==0){
        if(s1count==0){
            shead1=new stackstruct;
            shead1->id=p->id;
            shead1->time=p->time;
            shead1->next=NULL;
            shead1->pre=NULL;
            send1=shead1;
        }
        else{
            stackstruct *stack=new stackstruct;
            stack->id=p->id;
            stack->time=p->time;
            send1->next=stack;
            stack->pre=send1;
            stack->next=NULL;
            send1=stack; 
        }
        s1count++;
    }
    else if(flag==1){
        if(s2count==0){
            shead2=new stackstruct;
            shead2->id=p->id;
            shead2->time=p->time;
            shead2->next=NULL;
            shead2->pre=NULL;
            send2=shead2;
        }
        else{
            stackstruct *stack=new stackstruct;
            stack->id=p->id;
            stack->time=p->time;
            send2->next=stack;
            stack->pre=send2;
            stack->next=NULL;
            send2=stack;
        }
        s2count++;
    }
}
stackstruct *pop(int id,int time){
    stackstruct *stack;
    stack=new stackstruct;
    if(send1->id!=id){
        stack->id=send1->id;
        stack->time=send1->time;
        stack->pre=send1->pre;
        delete send1;
        send1=stack->pre;
        send1->next=NULL;
        s1count--;
    }
    else{
        stack->id=send1->id;
        stack->time=send1->time;
        stack->pre=send1->pre;
        cout<<id<<"�������뿪ͣ����"<<endl;
        cout<<"������ͣ������ͣ��ʱ��:"<<time-stack->time<<endl;
        cout<<"������Ҫ����"<<3*(time-stack->time)<<endl;
        delete send1;
        if(--s1count==0){
        send1=shead1=NULL;
        }
        else{
            send1=stack->pre;
            send1->next=NULL;
        }
        stack=NULL;
    }
    return stack;
}
struct stackstruct *pop1()
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
	stack->id = send2->id;
	stack->time = send2->time;
	stack->pre = send2->pre;
	free(send2);
	send2 = stack->pre;
	s2count--;

	return stack;
}
void Enqueue(struct stackstruct *p)
{
	struct queuestruct *queue;
	if (qcount == 0)
	{
		qhead = new queuestruct;
		qhead->id = p->id;
		qhead->next = NULL;
		qend = qhead;
	}
	else
	{
		queue = new queuestruct;
		queue->id = p->id;
		queue->next = NULL;
		qend->next = queue;
		qend = queue;
	}
	qcount++;
}
struct stackstruct *Dequeue(int time)
{
	struct stackstruct *stack;
	stack = new stackstruct;

	stack->id = qhead->id;
	stack->time = time;
	if (--qcount == 0)
	{
		qhead = NULL;
		qend = NULL;
	}
	else
		qhead = qhead->next;
	return stack;
}
int main()
{
	int n;
	char s;
	struct stackstruct *p;
	printf("�������ͣ����������: ");
	scanf("%d", &n);
	getchar();
	s1count = s2count = qcount = 0;
	p = (struct stackstruct *)malloc(sizeof(struct stackstruct));
	while (scanf("(%c,%d,%d)", &s, &p->id, &p->time) != EOF)
	{
		getchar();
		if (s == 'E')
			break;
		else if (s == 'A')                /*��������*/
		{
			if (s1count < n)                 /*ջδ������ջ����*/
			{
				push(0, p);
				cout<<send1->id<<"����������ͣ����"<<endl;
				cout<<"����ͣ����ʱ��:"<<send1->time<<endl;
				cout<<"ͣ��λ��: "<<s1count<<endl;
			}
			else                                /*ջ���������в���*/
			{
				Enqueue(p);
				cout<<p->id<<"������������"<<endl;
				cout<<"������ʱ��: "<<p->time<<endl;
				cout<<"���λ��: "<<qcount<<endl;
			}
		}
		else if (s == 'D')                /*������ȥ*/
		{
			struct stackstruct *temp;
			while ((temp = pop(p->id, p->time)) != NULL)
			{
				push(1, temp);
			}
			while (s2count != 0)
			{
				push(0, pop1());
			}
			if (qcount != 0)
			{
				push(0, Dequeue(p->time));
				cout<<send1->id<<"����������ͣ����"<<endl;
				cout<<"����ͣ����ʱ��:"<<send1->time<<endl;
				cout<<"ͣ��λ��: "<<s1count<<endl;
			}
		}
	}
	return 0;
}