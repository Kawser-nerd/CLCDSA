#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MAXN=1e5+5;
int a[MAXN];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bool flag=false;
        int four=0,one=0,two=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            {
                if(a[i]%4==0) four++;
                else if(a[i]%2==0) two++;
                else one++;
            }
        }
        if(one>four+1||(one==four+1&&two!=0)) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}