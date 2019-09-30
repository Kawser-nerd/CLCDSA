#include <stdio.h>
#include <queue>
using namespace std;
int cnt=1,trie[40000][10],fail[40000];
inline void advance(int &a,int b)
{
    if (!trie[a][b-1])
        trie[a][b-1]=++cnt;
    a=trie[a][b-1];
}
bool out[40000];
int dp[41][40000];
const int MOD=1000000007;
inline void add(int &a,int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
}
int main()
{
    int n,x,y,z;
    scanf("%d%d%d%d",&n,&x,&y,&z);
    for (int i=0;i<(1<<(x-1));++i)
        for (int j=0;j<(1<<(y-1));++j)
            for (int k=0;k<(1<<(z-1));++k)
            {
                int cur=1;
                for (int l=0,t=0;l<x;++l)
                {
                    ++t;
                    if (l==x-1||((i>>l)&1))
                    {
                        advance(cur,t);
                        t=0;
                    }
                }
                for (int l=0,t=0;l<y;++l)
                {
                    ++t;
                    if (l==y-1||((j>>l)&1))
                    {
                        advance(cur,t);
                        t=0;
                    }
                }
                for (int l=0,t=0;l<z;++l)
                {
                    ++t;
                    if (l==z-1||((k>>l)&1))
                    {
                        advance(cur,t);
                        t=0;
                    }
                }
                out[cur]=true;
            }
    fail[1]=1;
    queue<int> q;
    for (int i=0;i<10;++i)
        if (trie[1][i])
        {
            fail[trie[1][i]]=1;
            q.push(trie[1][i]);
        }
    while (!q.empty())
    {
        int f=q.front();
        q.pop();
        for (int i=0;i<10;++i)
            if (trie[f][i])
            {
                int val=fail[f];
                while (val!=1&&!trie[val][i])
                    val=fail[val];
                if (trie[val][i])
                    val=trie[val][i];
                q.push(trie[f][i]);
                fail[trie[f][i]]=val;
            }
    }
    dp[0][1]=1;
    for (int i=0;i<n;++i)
        for (int j=1;j<=cnt;++j)
        {
            if (out[j])
            {
                add(dp[i+1][j],(long long)dp[i][j]*10%MOD);
                continue;
            }
            for (int k=0;k<10;++k)
            {
                int val=j;
                while (val!=1&&!trie[val][k])
                    val=fail[val];
                if (trie[val][k])
                    val=trie[val][k];
                add(dp[i+1][val],dp[i][j]);
            }
        }
    int ans=0;
    for (int i=1;i<=cnt;++i)
        if (out[i])
            add(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}