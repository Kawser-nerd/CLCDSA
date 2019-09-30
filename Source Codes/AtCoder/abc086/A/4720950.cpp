// https://abc086.contest.atcoder.jp/tasks/abc086_a

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b;
    c = a * b % 2;

    if (c == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }

    return 0;
}