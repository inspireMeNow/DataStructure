#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace  std;
struct Project{ //项目
    string name;
    string id;
    string property;
};
struct Player{ //选手
    string name;
    string id;
    string sex;
    string department;
    string project;
    int grade;
    int rank;
};
struct Group{
    string name;
    string project;
    int grade;
    int rank;
};
int searchProject(Project project[],string a,int n){ //查找项目
    for(int i=0;i<n;i++){
        if(!project[i].name.compare(a)){ //找到项目
            if(!project[i].property.compare("个人项目")){
                return 1;
            }
            if(!project[i].property.compare("集体项目")){
                return 2;
            }
        }
    }
    return 0;
}
void deleteProject(Player player[],Project project[],int &playerNumber,int &projectNumber) { //删除参加人数小于3人的项目
    int count=0;
    string a;
    for(int i=0;i<projectNumber;i++) {
        count=0;
        for(int j=0;j<playerNumber;j++) {
            if(!player[j].project.compare(project[i].name)){
                count++;
            }
        }
        if(count<3){
            a=project[i].name;
            cout<<"参加"<<project[i].name<<"项目的人数少于三人，即将被删除！"<<endl;
            int j=0;
            for(int i=1;i<playerNumber;i++){
                if(player[i].project.compare(a)){
                    j++;
                    player[j]=player[i];
                }
            }
            playerNumber=j+1;
            j=0;
            for(int i=0;i<projectNumber;i++){
                if(project[i].name.compare(a)){
                    j++;
                    project[j]=project[i];
                }
            }
            projectNumber=j+1;
        }
    }
}
bool comp(Player player1,Player player2){ //成绩排名
    if(!player1.project.compare(player2.project)){
        return player1.grade>player2.grade;
    }
    return player1.project<player2.project;
}
bool comp1(Group player1,Group player2){
    if(!player1.project.compare(player2.project)){
        return player1.grade>player2.grade;
    }
    return player1.project<player2.project;
}
vector<string> getDepart(Player player[],int playerNumber){
    vector<string> string;
    for(int j=0;j<playerNumber;j++){
        string.insert(string.begin(),player[j].department);
    }
    vector<std::string>::iterator i= std::unique(string.begin(), string.end());
    string.erase(i,string.end());
    ofstream outfile;
    outfile.open("参赛单位清单.dat",ios::app);
    for(int j=0;j<string.size();j++){
        outfile<<setw(10)<<left<<string.at(j)<<endl;
    }
    return string;
}
void printFile(string s){ //读出文件
    char data;
    ifstream infile;
    infile.open(s);
    if (!infile) {
        cout << "读出数据失败！" << endl;
    } else {
        while ((data = infile.get()) != EOF) {
            cout << data;
        }
    }
    infile.close();
}
void writeFile(string s,Player player[],int playerNumber,int flag,string str){ //写入文件
    string a;
    switch(flag){
        case 1:a="男";break;
        case 2:a="女";break;
        default:break;
    }
    ofstream outfile;
    outfile.open(s, ios::app);
    if(flag!=1&&flag!=2){
        ofstream outfile1;
        outfile1.open(s);
        outfile1<<setw(10) << left << "学号" << setw(10) << "姓名" << setw(8) << "性别" <<setw(10)<<"单位" <<setw(10) << "参赛项目" << setw(5)<<"分数"<<setw(5)<<"排名"<<endl;
        outfile1.close();
    }
    for (int i = 0; i < playerNumber; i++) {
        if(!(a.compare(player[i].sex))||(!str.compare(player[i].department))||flag==4)
        outfile << setw(10) << left << player[i].id << setw(10) << player[i].name << setw(8)
                << player[i].sex << setw(10) <<player[i].department<<setw(10)<< player[i].project <<setw(5)<<player[i].grade<<setw(5)<<player[i].rank<< endl;
    }
    outfile.close();
}
int main() {
    int flag;
    Project project[1000];
    Player player[1000];
    Group group[1000];
    int playerNumber; //参赛选手数
    int projectNumber; //项目数
    int groupNumber; //参赛集体数
    vector<string> department; //参赛单位
    cout<<"欢迎使用运动会成绩管理系统"<<endl;
    cout<<"注意：第一次使用系统请先进行初始化!"<<endl;
    for(;;) {
        cout << setw(20) << left << "1、录入数据操作" << setw(20) << left << "2、读出数据操作" << endl << setw(20) << left
             << "3、初始化操作" << setw(20) << left << "4、退出系统" << endl;
        cout << "请选择操作：";
        cin >> flag;
        if (flag == 3) { //生成表头
            ofstream outfile;
            outfile.open("项目清单.dat");
            outfile << setw(10) << left << "项目号" << setw(14) << "项目名" << setw(10) << "项目性质" << endl;
            outfile.close();
            outfile.open("参赛选手清单.dat");
            outfile << setw(10) << left << "学号" << setw(10) << "姓名" << setw(8) << "性别" <<setw(10)<<"单位" <<setw(10) << "参赛项目" << endl;
            outfile.close();
            outfile.open("参赛单位清单.dat");
            outfile << setw(10) << left << "参赛单位" << endl;
            outfile.close();
            outfile.open("参赛集体清单.dat");
            outfile<< setw(10) << left << "参赛小组" << setw(10) << "参赛项目" << endl;
            outfile.close();
            outfile.open("男生比赛得分清单.dat");
            outfile<<setw(10) << left << "学号" << setw(10) << "姓名" << setw(8) << "性别" <<setw(10)<<"单位" <<setw(10) << "参赛项目" << setw(5)<<"分数"<<setw(5)<<"排名"<<endl;
            outfile.close();
            outfile.open("女生比赛得分清单.dat");
            outfile<<setw(10) << left << "学号" << setw(10) << "姓名" << setw(8) << "性别" <<setw(10)<<"单位" <<setw(10) << "参赛项目" << setw(5)<<"分数"<<setw(5)<<"排名"<<endl;
            outfile.close();
            outfile.open("参赛集体得分清单.dat");
            outfile<<setw(10)<<left<<"参赛小组"<<setw(10)<<"参赛项目"<<setw(5)<<"成绩"<<setw(5)<<"排名"<<endl;
            outfile.close();
            cout << "初始化系统成功！" << endl;
        } else if (flag == 1) {
            cout << "请选择需要录入的数据:" << endl;
            cout << setw(20) << left << "1、项目清单"<<setw(20)<<"2、参赛选手清单" << endl << setw(20) << "3、参赛集体清单"<<setw(20)<<"4、比赛成绩清单" << endl;
            cout << "请选择：";
            cin >> flag;
            while (flag != 1 && flag != 2 && flag != 3 && flag != 4&&flag!=5) {
                cout << "输入错误，请重新输入！" << endl;
                cin >> flag;
            }
            if (flag == 1) {
                int n;
                cout << "请输入总项目数:";
                cin >> n;
                cout << "请输入项目号和项目名：\n";
                for (int i = 0; i < n; i++) {
                    cin >> project[i].id >> project[i].name >> project[i].property;
                    projectNumber++;
                }
                ofstream outfile;
                outfile.open("项目清单.dat", ios::app);
                for (int i = 0; i < projectNumber; i++) {
                    outfile << setw(10) << left << project[i].id << setw(14) << project[i].name << setw(10)
                            << project[i].property << endl;
                }
                cout << "录入成功！" << endl;
                outfile.close();
            } else if (flag == 2) {
                int n;
                cout << "请输入总参赛选手数:";
                cin >> n;
                cout << "请输入选手的学号、姓名、性别、单位以及参加的项目：\n";
                for (int i = 0; i < n; i++) {
                    cin >> player[i].id >> player[i].name >> player[i].sex;
                    cin>>player[i].department>> player[i].project;
                    while (searchProject(project, player[i].project, projectNumber) != 1) {
                        cout << "输入的项目不存在或无法参加该项目，请重新输入！" << endl;
                        cin >> player[i].id >> player[i].name >> player[i].sex >>player[i].department>> player[i].project;
                    }
                    playerNumber++;
                }
                ofstream outfile;
                outfile.open("参赛选手清单.dat", ios::app);
                for (int i = 0; i < n; i++) {
                    outfile << setw(10) << left << player[i].id << setw(10) << player[i].name << setw(8)
                            << player[i].sex <<setw(10)<<player[i].department<< setw(10) << player[i].project << endl;
                }
                cout << "参赛选手录入成功！" << endl;
                outfile.close();
                department=getDepart(player,playerNumber);
                cout<<"参赛单位录入成功!"<<endl;
            } else if (flag == 3) {
                int n;
                cout << "请输入总参赛集体数:";
                cin >> n;
                cout << "请输入参赛集体名称和参赛项目：\n";
                for (int i = 0; i < n; i++) {
                    cin >> group[i].name >> group[i].project;
                    while (searchProject(project, group[i].project, projectNumber) != 2) {
                        cout << "输入的项目不存在或无法参加该项目，请重新输入！" << endl;
                        cin >> group[i].name>>group[i].project;
                    }
                    groupNumber++;
                }
                ofstream outfile;
                outfile.open("参赛集体清单.dat", ios::app);
                for (int i = 0; i < n; i++) {
                    outfile << setw(10) << left << group[i].name << setw(10) << group[i].project << endl;
                }
                cout << "录入成功！" << endl;
                outfile.close();
            }
            else {
                cout<<"请选择"<<endl<<setw(20)<<left<<"1、学生成绩录入"<<"2、集体成绩录入"<<endl;
                cin>>flag;
                if(flag==1) {
                    cout<<"本系统的成绩记录方式有："<<endl;
                    cout<<setw(10)<<"1、按性别记录"<<endl<<"2、按项目记录"<<endl<<"3、按参赛单位"<<endl;
                    deleteProject(player,project,playerNumber,projectNumber);
                    cout<<"请填入运动员的成绩："<<endl;
                    for(int i=0;i<playerNumber;i++){
                        cout<<player[i].name<<"的成绩：";
                        cin>>player[i].grade;
                        while(player[i].grade<0||player[i].grade>10){
                            cout<<"成绩输入非法，请重新输入！"<<endl;
                            cin>>player[i].grade;
                        }
                    }
                    sort(player,player+playerNumber,comp);
                    for(int i=1;i<=playerNumber;i++){
                        player[i].rank=i;
                    }
                        writeFile("男生比赛得分清单.dat",player,playerNumber,1,"");
                        writeFile("女生比赛得分清单.dat",player,playerNumber,2,"");
                    writeFile("比赛得分清单.dat",player,playerNumber,4,"");
                       for(int i=0;i<department.size();i++){
                           writeFile(department.at(i)+"比赛得分清单.dat",player,playerNumber,3,department.at(i));
                       }
                       cout<<"成绩录入成功！"<<endl;
                }
                else if(flag==2){
                    cout<<"请输入参赛集体的成绩："<<endl;
                    for(int i=0;i<groupNumber;i++){
                        cout<<group[i].name<<"的成绩：";
                        cin>>group[i].grade;
                        while(group[i].grade<0||group[i].grade>20){
                            cout<<"成绩输入非法，请重新输入！"<<endl;
                            cin>>group[i].grade;
                        }
                    }
                    sort(group,group+groupNumber,comp1);
                    for(int i=1;i<=groupNumber;i++){
                        group[i].rank=i;
                    }
                    ofstream outfile;
                    outfile.open("参赛集体得分清单.dat",ios::app);
                    for(int i=0;i<groupNumber;i++){
                        outfile<<setw(10)<<left<<group[i].name<<setw(10)<<group[i].project<<setw(5)<<group[i].grade<<setw(5)<<group[i].rank<<endl;
                    }
                    outfile.close();
                }
            }
        } else if (flag == 2) {
            cout << "请选择需要读出的数据:" << endl;
            cout << "1、项目清单\t2、参赛选手清单\n3、参赛单位清单\t4、参赛集体清单\n5、比赛成绩清单\n";
            cout << "请选择：";
            cin >> flag;
            while (flag != 1 && flag != 2 && flag != 3 && flag != 4&&flag!=5) {
                cout << "输入错误，请重新输入！" << endl;
                cin >> flag;
            }
            char data;
            if (flag == 1) {
                printFile("项目清单.dat");
            } else if (flag == 2) {
                printFile("参赛选手清单.dat");
            } else if (flag == 3) {
                printFile("参赛单位清单.dat");
            }
            else if(flag==4) {
                printFile("参赛集体清单.dat");
            } else {
                    cout<<"请选择需要导出的成绩单："<<endl;
                    cout<<"请选择："<<endl<<setw(10)<<"1、个人项目成绩单"<<setw(10)<<"2、集体项目成绩单"<<endl;
                    cin>>flag;
                    if(flag==1){
                        cout<<"请选择："<<endl;
                        cout<<setw(10)<<left<<"1、按性别分类"<<setw(10)<<"2、按项目分类"<<endl<<setw(10)<<left<<"3、按各参赛单位分类";
                        cin>>flag;
                        switch(flag){
                            case 1:
                                cout<<"请选择："<<endl<<setw(15)<<"1、男生比赛得分清单"<<setw(15)<<"2、女生比赛得分清单"<<endl;
                                cin>>flag;
                                if(flag==1){
                                    printFile("男生比赛得分清单.dat");
                                }
                                else if(flag==2){
                                    printFile("女生比赛得分清单.dat");
                                }
                                else{
                                    cout << "输入错误，请重新输入！" << endl;
                                }
                                break;
                                case 2:
                                    printFile("比赛得分清单.dat");
                                    break;
                                    case 3:
                                        cout<<"请选择："<<endl;
                                        for(int i=0;i<department.size();i++){
                                            cout<<setw(10)<<i+1<<"、"<<department.at(i)<<endl;
                                        }
                                        cin>>flag;
                                        for(int i=0;i<department.size();i++){
                                            if(flag==i+1){
                                                printFile(department.at(i)+"成绩清单.dat");
                                            }
                                        }
                                        break;
                        }
                    }
                    else if(flag==2){
                        printFile("参赛集体得分清单.dat");
                    }
                    else{
                        cout<<"输入错误，请重新输入！"<<endl;
                    }
                }
            }
        else if (flag == 4) {
            cout << "系统即将退出，再见！" << endl;
            break;
        }
    }
    return 0;
}