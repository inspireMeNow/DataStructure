#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
 
using namespace std;
struct Part{
    string src; //始发地
    string edge; //边
    string dst; //目的地
};
 
void input(vector<Part> &NFA, int num){
    for(int i=0;i<num;i++){
        Part temp;
        cin>>temp.src>>temp.edge>>temp.dst;
        NFA.push_back(temp);
    }
}
 
void outputNFA(vector<Part> NFA){
    for(int i=0;i<NFA.size();i++){
        cout<<NFA[i].src<<" "<<NFA[i].edge<<" "<<NFA[i].dst<<endl;
    }
}
 
bool check(string str, char x){
    for(int i=0;i<str.length();i++){
        if(str[i]==x)
            return true; //检查字符是否匹配
    }
    return false;
}
 
string closure(string setp, vector<Part> NFA){ //构造闭包
    for(int i=0;i<setp.length();i++){
        for(int j=0;j<NFA.size();j++){
            if(setp[i]==NFA[j].src[0]&&NFA[j].edge[0]=='&'){ //边为ε的情况
                if(!check(setp,NFA[j].dst[0])){
                    setp+=NFA[j].dst[0];
                }
            }
        }
    }
    return setp;
}
 
string move(string t, char a, vector<Part> NFA){ //返回路径为a的所有dist
    string temp="";
    for(int i=0;i<t.length();i++){
        for(int j=0;j<NFA.size();j++){
            if(t[i]==NFA[j].src[0]&&NFA[j].edge[0]==a){
                if(!check(temp,NFA[j].dst[0])){ //检查dist是否已经存在
                    temp+=NFA[j].dst[0]; //将所有dist存入temp变量
                }
            }
        }
    }
    return temp;
}
 
bool checkINrawDFA(vector<string> rawDFA, string u){ //检查是否在已有的开始闭包中
    for(int i=0;i<rawDFA.size();i++){
        if(rawDFA[i]==u)
            return true; //已经存在则返回true
    }
    return false; //不存在返回false
}
 
int checkFlag(vector<bool> t){ 
    for(int i=0;i<t.size();i++){
        if(t[i]==false)return i; //返回首个未标记的闭包的index值
    }
    return -1;
}
 
int main(int argc, const char * argv[]) {
    vector<Part> NFA;
    int num;
    cout<<"请输入边的条数：";
    cin>>num;
    getchar();
    cout<<"请输入每条边的起点、弧上所接受的输入字符和终点："<<endl;
    input(NFA,num);
    
    char sigma[2]={'a','b'}; //字母表
    string start = closure("0", NFA); //k起始符的闭包
    sort(start.begin(), start.end());
    vector<string> rawDFA; //存入子集
    rawDFA.push_back(start);
    vector<bool> rawDFAflag; //存入子集是否完成的标志
    rawDFAflag.push_back(false);
    while(checkFlag(rawDFAflag)!=-1){ //检查所有闭包是否被标记
        int m = checkFlag(rawDFAflag);
        rawDFAflag[m]=true; //设置当前开始闭包的flag为true，表示已经完成
        for(int i=0;i<2;i++){
            string u = closure(move(rawDFA[m],sigma[i],NFA), NFA); //构造闭包
            sort(u.begin(), u.end()); //对闭包结果排序
            if(!checkINrawDFA(rawDFA, u)){ //检查是否在已有的开始闭包中
                rawDFA.push_back(u);
                rawDFAflag.push_back(false); //将flag置为false表示已在开始闭包中
            }
        }
    }
    cout<<endl;
    cout<<"确定化过程为："<<endl;
    cout<<"\t"<<"|Ia"<<"\t"<<"|Ib"<<"\t|"<<endl;
    for(int i=0;i<rawDFA.size();i++){
        cout<<"|"<<rawDFA[i]<<"\t|"<<closure(move(rawDFA[i],'a',NFA),NFA)<<"\t|"<<closure(move(rawDFA[i],'b',NFA),NFA)<<"\t|"<<endl; //输出DFA
    }
    return 0;
}