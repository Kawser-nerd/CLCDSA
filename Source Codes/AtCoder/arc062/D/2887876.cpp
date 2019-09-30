#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const ll N=205;
const ll mod=1e9+7;
ll dfn[N],low[N],tot;
struct node{
    int u,v,nxt,rev;
    bool vis;
}edge[N];
int head[N],mcnt;
void add_edge(int u,int v,int rev){
    mcnt++;
    edge[mcnt].u=u;
    edge[mcnt].v=v;
    edge[mcnt].nxt=head[u];
    edge[mcnt].rev=rev;
    head[u]=mcnt;
}
int s[N],top;
ll scc[N],sccc;
bool vis[N];
ll p[N];
ll n,m,k;
ll gcd(ll x,ll y){
    ll t;
    while(y){
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}
ll ksm(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
ll polya(ll x){
    ll res=0;
    for(int i=1;i<=x;i++)
        res+=ksm(k,gcd(x,i)),res%=mod;
    res*=ksm(x,mod-2);
    res%=mod;
    return res;
}
ll u1[N],v1[N];
ll fact[N+1],inv[N+1];
ll ans=1;
void pre(){
    fact[0]=1;
    for(int i=1;i<=N;i++)
        fact[i]=(fact[i-1]*i)%mod;
    inv[N]=ksm(fact[N],mod-2);
    for(int i=N-1;i>=1;i--)
        inv[i]=(inv[i+1]*(i+1))%mod;
    inv[0]=1;
}
ll C(ll x,ll y){
    return fact[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs(ll u,ll fa){
    tot++;
    dfn[u]=low[u]=tot;
    for(int i=head[u];i;i=edge[i].nxt){
        ll v=edge[i].v;
        if(v==fa||edge[i].vis)
            continue ;
        s[++top]=i;
        edge[i].vis=1;
        edge[edge[i].rev].vis=1;
        if(!dfn[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                bool cir=1;
                int cnt=0;
                ll sum=0;
                int x;
                int sz=0;
                for(int j=top;s[j+1]!=i;sz++,j--)
                    if(vis[edge[s[j]].v])
                        cir=0;
                    else
                        vis[edge[s[j]].v]=1;
                    if(sz==1){
                    ans*=k;
                    ans%=mod;
                }
                else if(cir){
                    ans*=polya(sz);
                    ans%=mod;
                }
                else{
                    ans*=C(sz+k-1,k-1);
                    ans%=mod;
                }
                while(s[top+1]!=i){
                    vis[edge[s[top]].v]=0;
                    top--;
                }
            }
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=m;i++){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        add_edge(u,v,mcnt+2);
        add_edge(v,u,mcnt);
        u1[i]=u;
        v1[i]=v;
    }
    pre();
    for(ll i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i,-1);
    printf("%lld\n",ans);
}