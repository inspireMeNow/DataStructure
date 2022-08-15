# include <iostream>
# include <string>
using namespace std;
class Node{
public:
	int data;
	int id;
	Node *next;
	Node(int e,Node *link){
    data=e;
    next=link;
    }
    Node(){}
};
class CycleList{
public:
	int length;
	/*CycleList(){
	Node *head=new Node;
	head->data=0;
	head->next=head;
	}*/
	Node *CreateLinkList(Node* &first,int n){
		int e;
        Node *p,*r=NULL;
        first=NULL;
        for(int i=0;i<n;i++){
        cin>>e;
        p=new Node(e,NULL);
        if(first!=NULL)r->next=p;
        else first=p;
        r=p;
        }
		return first;
	}
    void Print(Node* &first){
		Node *p=first;
        while(p){
        cout<<p->data<<" ";
        p=p->next;
        }
    }
    Node *InsertList(Node* &first,int m,int n){
        int e;
		cin>>e;
		Node *temp=first;
        for(int i=1;i<m&&temp;i++){
			if(temp==NULL||m>n||m<1) {
            printf("error!\n");
            return first;
        }
            temp=temp->next;
        }
		Node *q=new Node(e,NULL);
		q->next=temp->next;
		temp->next=q;
		return first;
    }
/*	bool IsEmpty(){
	if(head->next==head)
		return 1;
	else
		return 0;
	}
	void Judge(int n){
	Node *pre=NULL;
	int count=0,loop=0;
	Node *p=head,*q;
	while(p!=p->next){
	count++;
	if(!(count%(n-1)))
		loop++;
	    q=p->next;
		p->next=q->next;
		cout<<q->data<<" ";
		delete q;
	}
	p=p->next;
	cout<<p->data;
	}*/
};
int main()
{
	int n;
	CycleList a;
    Node *e;
	cout<<"input the length:";
	cin>>n;
	//a.CreateLinkList(n);
	cout<<"input the array:"<<endl;
    e=a.CreateLinkList(e,n);
    a.Print(e);
    int m;
	cout<<"input the insert location:"<<endl;
	cin>>m;
	cout<<"input the number:"<<endl;
	e=a.InsertList(e,m,n);
	/*int m=20;
	cin>>m;
	a.Judge(m);
	cout<<endl;*/
	a.Print(e);
    //system("pause");
	return 0;
}