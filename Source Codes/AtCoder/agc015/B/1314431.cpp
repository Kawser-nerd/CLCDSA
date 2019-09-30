#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdlib>
#include<string>
#include<algorithm>
#define LL long long
#define INF 1000000009
using namespace std;
int main()
{
    char s[100001];
    scanf("%s",s);
    int len=strlen(s);
    LL ans=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='U')
        {
            ans+=(len+i-1);
        }
        else
        ans+=(2*len-i-2);
    }
    printf("%lld\n",ans);
}