#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 2e5+55;
int vis[MAXN];
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    vis[a]++;
    vis[b]++;
    vis[c]++;
    if(vis[5]==2&&vis[7]==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}