#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
lli MOD = 1000000007;
string b = "Second";
string a = "First";
int main()
{
    string s;
    cin >> s;
    int k = s.size();
    int c = s[0] == s[s.size() - 1];
    k %= 2;
    if (c ^ k)
        cout << a << endl;
    else
        cout << b << endl;
}