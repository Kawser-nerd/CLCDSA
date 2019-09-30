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

    
    int a, b;
    cin >> a >> b;
    map<int, int> mp1, mp2, mp3;
    mp1.clear();mp2.clear();mp3.clear();
    mp1[1]=1;mp1[3] = 1; mp1[5] = 1; mp1[7] = 1;mp1[8] = 1;mp1[10] = 1;mp1[12] = 1;
    mp2[4] = 1;mp2[6] = 1;mp2[9] = 1;mp2[11] = 1;mp3[2] = 1;
    if(mp1[a] && mp1[b])
        printf("Yes\n");
    else if(mp2[a] && mp2[b])
        printf("Yes\n");
    else if(mp3[a] && mp3[b])
        printf("Yes\n");
    else printf("No\n");
    return 0;
}