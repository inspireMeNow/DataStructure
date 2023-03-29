#include <iostream>
using namespace std;
bool check(int a)
{
    while (a)
    {
        if (a % 10 == 2 || a % 10 == 4)
        {
            return false;
        }
        a = a / 10;
    }
    return true;
}
int main()
{
    int n = 2019;
    int k;
    int count = 0;
    for (int i = 1; i <= 2019; i++)
    {
        for (int j = i + 1; j <= 2019 - i; j++)
        {
            k = n - i - j;
            if (check(i) && check(j) && check(k) && i < j && j < k)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}