#include <iostream>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    cout << str.replace(0, 4, "2018") << endl;

    return 0;
}