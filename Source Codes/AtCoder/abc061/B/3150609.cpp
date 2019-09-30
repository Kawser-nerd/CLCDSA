#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int main()
{

    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    mp.clear();
    int a, b;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&a,&b);
        mp[a]++;mp[b]++;
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n",mp[i]);
    return 0;
}