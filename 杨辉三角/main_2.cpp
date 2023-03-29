#include <iostream>
#include <cmath>
using namespace std;
long long N;
long long combination(long long m, long long n)
{
    long long res = 1;
    for (int i=n,j=1;j<=m;j++,i--)
    {
        res *= i;
        res /= j;
        if (res > n)
        {
            return res;
        }
    }
    return res;
}
long long search(int column)
{
    int left = column * 2;
    int right = max((int)N, left);
    int mid = (left + right) /2;
    long long temp;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        temp = combination(column, mid);
        if (temp == N)
        {
            break;
        }
        if (temp > N)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (combination(column, mid) == N)
    {
        return (long)mid * (mid + 1) / 2 + column + 1;
    }
    return -1;
}
int main()
{
    cin >> N;
    long long count;
    for (int i = 16; i >= 0; i--)
    {
        count = search(i);
        if (count != -1)
        {
            cout << count << endl;
            break;
        }
    }
    return 0;
}