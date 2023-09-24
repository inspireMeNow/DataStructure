#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#define MAX 1111

using namespace std;

struct state_transition
{
    char start_point; //开始节点
    char edge;        //弧上所接受的输入字符
    char end_point;   //结束节点
};

//求集合的差
void subset(char *s1, char *s2, char *s)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0, j = 0, cnt = 0; i < len1; i++, j = 0)
    {
        for (; j < len2; j++)
        {
            if (s1[i] == s2[j])
                break;
        }
        if (j >= len2)
        {
            s[cnt++] = s1[i];
        }
    }
}

//判断下一个状态属于哪个集合
int jude_set(char result[MAX][MAX], int rlen, char ch1, char ch2, state_transition *dfam, int tlen)
{

    for (int i = 0; i < tlen; i++)
    {
        if (ch1 == dfam[i].start_point && ch2 == dfam[i].edge)
        { //开始节点和边对应
            for (int t = 0; t < rlen; t++)
            {
                for (int j = 0; j < strlen(result[t]); j++)
                {
                    if (dfam[i].end_point == result[t][j])
                    {             //结束节点对应
                        return t; //找到下一状态的集合
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    state_transition DFAM[MAX];
    char state[MAX];
    char finaly[MAX];
    char s[MAX];
    char result[MAX][MAX];
    int cnt = 0;
    char ch;
    cout << "请输入DFA的总状态：" << endl;
    while (true)
    {
        cin >> ch;
        if (ch == '#')
            break;
        state[cnt++] = ch;
    }
    //输入终态集
    cout << "请输入DFA的终态：" << endl;
    cnt = 0;
    while (true)
    {
        cin >> ch;
        if (ch == '#')
            break;
        finaly[cnt++] = ch;
    }
    //通过邻接矩阵存储输入状态关系
    cnt = 0;
    while (true)
    {
        cin >> DFAM[cnt].start_point >> DFAM[cnt].edge >> DFAM[cnt].end_point;
        if (DFAM[cnt].start_point == '#' && DFAM[cnt].edge == '#' && DFAM[cnt].end_point == '#')
            break;
        cnt++;
    }

    //把总状态分为终态与非终态
    subset(state, finaly, s);
    strcpy(result[0], s);

    int set_count = 1;
    while (true)
    {
        bool flag = false;
        int t1, t2;
        t1 = jude_set(result, set_count, result[set_count - 1][0], 'a', DFAM, cnt);
        t2 = jude_set(result, set_count, result[set_count - 1][0], 'b', DFAM, cnt);
        char temp[MAX] = {result[set_count - 1][0]};
        for (int j = 1, c = 0; j < strlen(result[set_count - 1]); j++)
        {
            if (t1 == jude_set(result, set_count, result[set_count - 1][j], 'a', DFAM, cnt) &&
                t2 == jude_set(result, set_count, result[set_count - 1][j], 'b', DFAM, cnt)) //找到对应集合
            {
                temp[++c] = result[set_count - 1][j];
            }
            else
                flag = true; //标志未找到
        }
        if (flag) //未找到的情况
        {
            char temp1[MAX] = "";
            subset(result[set_count - 1], temp, temp1);
            strcpy(result[set_count - 1], temp);
            strcpy(result[set_count++], temp1);
        }
        else
            break;
    }
    strcpy(result[set_count++], finaly); //将终态放入邻接矩阵中
    while (true)
    {
        bool flag = false;
        int t1, t2;
        t1 = jude_set(result, set_count, result[set_count - 1][0], 'a', DFAM, cnt);
        t2 = jude_set(result, set_count, result[set_count - 1][0], 'b', DFAM, cnt);
        char temp[MAX] = {result[set_count - 1][0]};
        for (int j = 1, c = 0; j < strlen(result[set_count - 1]); j++)
        {
            if (t1 == jude_set(result, set_count, result[set_count - 1][j], 'a', DFAM, cnt) &&
                t2 == jude_set(result, set_count, result[set_count - 1][j], 'b', DFAM, cnt)) //找到对应集合
            {
                temp[++c] = result[set_count - 1][j];
            }
            else //未找到
                flag = true;
        }
        if (flag) //未找到的情况
        {
            char temp1[MAX] = "";
            subset(result[set_count - 1], temp, temp1);
            strcpy(result[set_count - 1], temp);
            strcpy(result[set_count++], temp1);
        }
        else
            break;
    }

    cout << "化简后的DFA'新状态如下：" << endl;
    for (int i = 0, jj, len; i < set_count; i++)
    {
        len = strlen(finaly);
        for (jj = 0; jj < len; jj++)
        {
            if (result[i][0] == finaly[jj]) //到达终态退出循环
                break;
        }
        cout << i << "\t{";
        int j = 0;
        for (; j < strlen(result[i]) - 1; j++)
        {
            cout << result[i][j] << ",";
        }
        cout << result[i][j] << "}" << setw(6) << "\t"; //设置表格对齐
        if (jj >= len)
            cout << "普通状态" << endl;
        else
            cout << "终态" << endl;
    }
    cout << "化简后的DFA'的各状态关系如下：" << endl;
    for (int i = 0; i < set_count; i++)
    {
        if (jude_set(result, set_count, result[i][0], 'a', DFAM, cnt) != -1) //找到状态
            cout << i << " a " << jude_set(result, set_count, result[i][0], 'a', DFAM, cnt) << endl;
        if (jude_set(result, set_count, result[i][0], 'b', DFAM, cnt) != -1)
            cout << i << " b " << jude_set(result, set_count, result[i][0], 'b', DFAM, cnt) << endl;
    }
    return 0;
}
