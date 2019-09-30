#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=500010;
int n, x, num;
int cnt[maxn], tree[maxn], pos[26][maxn];
ll ans;
char s[maxn];
bool v[maxn];
inline void add(int x, int delta){for(;x<=n;x+=x&-x) tree[x]+=delta;}
inline int query(int x){int sum=0; for(;x;x-=x&-x) sum+=tree[x]; return sum;}
int main()
{
    scanf("%s", s+1); n=strlen(s+1);
    for(int i=1;i<=n;i++) cnt[x=s[i]-'a']++, pos[x][++pos[x][0]]=i, tree[i]=i&-i;
    for(int i=0;i<26;i++) if(cnt[i]&1) num++;
    if(num>1) return puts("-1"), 0;
    for(int i=1;i<=n;i++)
    if(!v[i])
    {
        int x=s[i]-'a', nxt=pos[x][pos[x][0]--];
        if(i==nxt) ans+=(query(n)-query(i))>>1;
        else ans+=query(n)-query(nxt);
        add(i, -1); add(nxt, -1); v[i]=v[nxt]=1;
    }
    printf("%lld\n", ans);
}