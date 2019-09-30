#include <iostream>
#include <algorithm>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int N,A,B,C,ans=INF;
int s[10];
void dfs(int n,int a,int b,int c,int col)
{
    if(n==N)
    {
        if(a&&b&&c)
            ans=min(ans,abs(a-A)+abs(b-B)+abs(c-C)+col);
        return;
    }
    dfs(n+1,a,b,c,col);
    dfs(n+1,a+s[n],b,c,col+10*(a>0));
    dfs(n+1,a,b+s[n],c,col+10*(b>0));
    dfs(n+1,a,b,c+s[n],col+10*(c>0));
}
int main()
{
    scanf("%d",&N);
    scanf("%d%d%d",&A,&B,&C);
    for(int i=0;i<N;i++)
        scanf("%d",&s[i]);
    dfs(0,0,0,0,0);
    cout << ans;
    return 0;
}