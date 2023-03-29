#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_palindromic(string s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}
int isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 29;
    else
        return 28;
}
bool is_date(string date)
{
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(4, 2));
    int day = stoi(date.substr(6, 2));
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return day <= 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return day <= 30;
        break;
    case 2:
        return day <= isLeapYear(year);
        break;
    default:
        return false;
        break;
    }
}
int main()
{
    string date;
    cin >> date;
    if (is_date(date))
    {
        string next_date;
        for (long long i = stoi(date) + 1;; i++)
        {
            next_date = to_string(i);

            if (is_palindromic(next_date) && is_date(next_date))
            {
                cout << next_date << endl;
                break;
            }
        }
        string ab_date;
        for (int year = stoi(date.substr(0, 4)); year <= 9999; year++)
        {
            string y = to_string(year).substr(0, 2);
            string reverse_y = y;
            reverse(reverse_y.begin(), reverse_y.end());
            ab_date = y + y + reverse_y + reverse_y;
            if (ab_date > date && is_date(ab_date))
            {
                cout << ab_date << endl;
                break;
            }
        }
    }
    return 0;
}
