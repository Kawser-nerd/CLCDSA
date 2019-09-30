#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
#define pb push_back
#define Key_value ch[ch[root][1]][0]
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define MS(x,y) memset(x,y,sizeof(x))
const double eps = 1e-6;
const double pi = acos (-1.0);
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int M = 300005;

int s[1050][1050];

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if(n % x == 0 && m % y == 0) return 0 * puts("No");
    cout << "Yes" << endl;
    for(int i = 0; i < n; i += x)
        for(int j = 0; j < m; j += y) s[i][j] = 1e6;
    for(int i = x - 1; i < n; i += x)
        for(int j = y - 1; j < m; j += y) s[i][j] = -1e6 -1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(j != m - 1) cout << s[i][j] << " ";
            else cout << s[i][j] << endl;
        }
    }

    return 0;
}