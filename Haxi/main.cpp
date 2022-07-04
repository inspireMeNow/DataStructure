# include <iostream>
# include <cstring>
# define R 30
# define NULLKEY -32768
using namespace std;
typedef struct {
int elem;
char pinyin[30];
}Name;
typedef struct {
Name *elem;
int count;
}HashTable;
int m=0;
int Hash(int k){
    return k%m;
}
void Insert(HashTable *h,int k,char a[]){
    int address=Hash(k);
    while(h->elem[address].elem!=NULLKEY){
    address=(address+1)%m;
    }
    h->elem[address].elem=k;
    strcpy(h->elem[address].pinyin,a);
}
int Init(HashTable *h){
    char *f;
    int i,j;
    int s0;
    m=R;
    h->elem=new Name[m];
    h->count=m;
    for(int i=0;i<m;i++){
        h->elem[i].elem=NULLKEY;
    }
    return 1;
}
int Search(HashTable *h,int k){
    int address=Hash(k);
    while(h->elem[address].elem!=k){
    address=(address+1)%m;
    if(h->elem[address].elem==NULLKEY||address==Hash(k)){
        return -1;
    }
    }
    return address;
}
void Result(HashTable *h){
    int i;
    for(i=0;i<h->count;i++){
        cout<<h->elem[i].elem<<" "<<h->elem[i].pinyin<<endl;
    }
}
int Convert(char *f){
      int s0=0;
      for(int j=0;;j++){
            s0=*(f+j)+s0;
            if(*(f+j)=='\0')
            break;
      }
      return s0;
}
int main(){
    int i,j,addr;
    HashTable h;
    char a[R][30];
    cout<<"Please input the name:"<<endl;
    Init(&h);
    int s0;
    char *f;
    for(i=0;i<m;i++){
        cin.getline(a[i],30);
        s0=Convert(a[i]);
        Insert(&h,s0,a[i]);
        //cout<<s0<<endl;
    }
    Result(&h);
    cout<<"Please input the name:"<<endl;
    char search[30];
    cin.getline(search,30);
    j=Convert(search);
    addr=Search(&h,j);
    if(addr==-1)
    cout<<"Not exist!"<<endl;
    else
    cout<<"The location is "<<addr+1<<endl;
    system("pause");
    return 0;
}