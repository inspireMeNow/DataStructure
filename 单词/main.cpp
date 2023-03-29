#include <iostream>
#include <cstring>
using namespace std;
char l[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main()
{
    string str;
    cin >> str;
    int count = 0;
    int temp = 0;
    char max;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j]==l[i])
            {
                count++;
            }
        }
        if (temp < count)
        {
            max=l[i];
            temp = count;
        }
        count=0;
    }
    cout<<max<<endl<<temp;
    return 0;
}