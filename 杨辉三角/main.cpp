#include <iostream>
using namespace std;
int main()
{
    long long triangle[2][47723];
    long long N;
    cin >> N;
    long long count = 0;
    for (long long i = 1; i < 44723; i++)
    {
        long long cur = i % 2;
        long long prev = (i - 1) % 2;
        triangle[cur][0] = 1;
        triangle[cur][i] = 1;
        for (long long j = 1; j < i -17000; j++)
        {
            triangle[cur][j] = triangle[prev][j - 1] + triangle[prev][j];
        }
        for (long long j = 0; j <= i -17000; j++)
        {
            count++;
            // cout<<triangle[cur][j]<<" ";
            if (N == 1)
            {
                cout << 1 << endl;
                return 0;
            }
            else
            {
                if (triangle[cur][j] == N)
                {
                    cout << count << endl;
                    return 0;
                }
            }
        }
    }
    cout << N * (N + 1) / 2 + 2;
    return 0;
}