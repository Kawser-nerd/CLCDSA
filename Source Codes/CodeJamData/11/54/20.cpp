#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

string s;
long long ans;

bool check(long long x)
{
    double t = x;
    t = sqrt(t);
    long long u = (long long)t;
    return u * u == x;
}

void dfs(int cur , long long carry)
{
    if(ans > 0)
        return;
    if(cur == s.length())
    {
        if(check(carry))
            ans = carry;
        return;
    }
    if(s[cur] == '1' || s[cur] == '?')
        dfs(cur + 1 , carry * 2 + 1);
    if(s[cur] == '0' || s[cur] == '?')
        dfs(cur + 1 , carry * 2 + 0);
}

void solve()
{
    ans = 0;
    cin >> s;
    dfs(0 , 0);
    string ret = "";
    while(ans)
    {
        if(ans % 2 == 1)
            ret = "1" + ret;
        else
            ret = "0" + ret;
        ans /= 2;
    }
    cout << ret << endl;
}

int main()
{
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int TestCase;
    cin >> TestCase;
    for(int CaseID = 1 ; CaseID <= TestCase ; CaseID ++)
    {
        cout << "Case #" << CaseID << ": ";
        solve();
    }
    //system("pause");
    return 0;
}
