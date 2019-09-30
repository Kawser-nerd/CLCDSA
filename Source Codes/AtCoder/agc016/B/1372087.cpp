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

int a[100050];

int main()
{
    int n;
    cin >> n;
    int aa = 0, bb = INF;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(a[i] > aa) aa = a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == aa) cnt++;
        if(a[i] < aa - 1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    
    if(cnt == n && aa + 1 == n)
    {
        cout << "Yes" << endl;
        return 0;
    }
    
    //cerr << aa << "  " << bb << endl;

    if(cnt == 1)
    {
        cout << "No" << endl;
        return 0;
    }

    int l = (n - cnt) + 1;
    int r = (n - cnt) + cnt / 2;
    if(l <= aa && aa <= r)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}