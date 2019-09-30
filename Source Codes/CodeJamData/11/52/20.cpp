#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int n;
int s[10002];
int d[10002];
int P[10002] , zP;
int N[10002] , zN;

void solve()
{
    cin >> n;
    zP = 0;
    zN = 0;
    memset(s , 0 , sizeof(s));
    for(int i = 1 ; i <= n ; i++)
    {
        int t;
        cin >> t;
        s[t] ++;
    }
    for(int i = 1 ; i <= 10001 ; i++)   
    {
        d[i] = s[i] - s[i-1];
        if(d[i] < 0)
        {
            for(int j = 1 ; j <= -d[i] ; j++)
                N[++zN] = i;
        }
        else if(d[i] > 0)
        {
            for(int j = 1 ; j <= d[i] ; j++)
                P[++zP] = i;
        }
        
    }
    int ans = 1000000;
    if(n == 0)
        ans = 0;
    for(int i = 1 ; i <= zN ; i++)
        ans = min(ans , N[i] - P[i]);
    cout << ans << endl;
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
