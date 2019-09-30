#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

int N, M;

#define MOD 1000000007

struct node{
    int count;
    node *next[27];
};

node nodes[1005*1005];
node *root=nodes;
int cnt=1;

int sum(int a, int b)
{
    a+=b;
    if(a>=MOD) a-=MOD;
    return a;
}

void add(int &a, int b)
{
    a=sum(a, b);
}

int mul(int a, int b)
{
    return 1ll*a*b%MOD;
}

int fact[1005];
int nCr[1005][1005];

int main()
{
    fact[0]=1;
    for(int i=1; i<1005; i++)
        fact[i]=mul(fact[i-1], i);
    for(int i=0; i<1005; i++)
    for(int j=0; j<1005; j++)
    {
        if(j>i) nCr[i][j]=0;
        else if(j==0 || j==i) nCr[i][j]=1;
        else nCr[i][j]=sum(nCr[i-1][j-1], nCr[i-1][j]);
    }
        
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d%d", &M, &N);
        memset(nodes, 0, sizeof(nodes));
        for(int i=0; i<M; i++)
        {
            char S[1005];
            scanf(" %s", S);
            node *at=root;
            for(int j=0; S[j]; j++)
            {
                int c=S[j]-'A';
                node *&next=at->next[c];
                if(!next) next=nodes+cnt++;
                at=next;
                at->count++;
            }
            at->next[26] = nodes+cnt++;
            at=at->next[26];
            at->count=1;
        }
        root->count=M;
        int ways=1;
        int ans=0;
        for(int i=0; i<cnt; i++)
        {
            ans+=min(N, nodes[i].count);
            if(nodes[i].count>=N && N!=1)
            {
                bool has=false;
                for(int j=0; j<27; j++)
                    if(nodes[i].next[j] && nodes[i].next[j]->count>=N)
                        has=true;
                if(!has)
                {
                    int dp[101] = {};
                    dp[0]=1;
                    for(int j=0; j<27; j++)
                    {
                        if(!nodes[i].next[j]) continue;
                        int cnt=nodes[i].next[j]->count;
                        int next[101]={};
                        for(int nc=0; nc<=cnt; nc++)
                        {
                            for(int old=cnt-nc; old+nc<=N; old++)
                            {
                                add(next[old+nc], mul(mul(fact[cnt], mul(nCr[old][cnt-nc], nCr[N-old][nc])), dp[old]));
                            }
                        }
                        for(int i=0; i<=N; i++)
                        {
                            //printf("%d ", next[i]);
                            dp[i]=next[i];
                        }
                        //puts("");
                    }
                    ways=mul(ways, dp[N]);
                }
                else
                {
                    for(int j=0; j<27; j++)
                    {
                        if(!nodes[i].next[j] || nodes[i].next[j]->count>=N) continue;
                        for(int k=0; k<nodes[i].next[j]->count; k++)
                        {
                            ways=mul(ways, N-k);
                        }
                    }
                }
            }
        }
        //assert(ways!=0);
        printf("Case #%d: %d %d\n", t, ans-M, ways);
    }
}
