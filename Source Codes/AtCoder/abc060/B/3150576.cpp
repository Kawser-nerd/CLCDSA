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

    int a, b, c;
    map<int,int> mp;
    mp.clear();
    int i;cin >> a >> b >> c;
    i = a;
    while(1)
    {
        mp[i % b]++;
        if(i % b == c % b)
        {
            printf("YES\n");
            break;
        }
        else
        {
            i += a;
        }
        if(mp[i % b])
        {
            printf("NO\n");
            break;
        }
    }
    return 0;
}