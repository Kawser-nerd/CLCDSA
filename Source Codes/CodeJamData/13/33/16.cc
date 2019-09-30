#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=1e6+5;

struct point
{
    int l,r,h,d;
} f[maxn];

bool operator <(const point &a,const point &b)
{
    return a.d<b.d;
}

int t,N,d,n,w,e,s,delta_d,delta_p,delta_s,g[maxn*2],m,k,r,now;
map<int,int> S;
int tree[maxn*6],ans,lazy[maxn*6];

void down(int pos)
{
    if(lazy[pos])
    {
        if(tree[pos<<1]<lazy[pos])tree[pos<<1]=lazy[pos];
        if(lazy[pos<<1]<lazy[pos])lazy[pos<<1]=lazy[pos];
        if(tree[(pos<<1)|1]<lazy[pos])tree[(pos<<1)|1]=lazy[pos];
        if(lazy[(pos<<1)|1]<lazy[pos])lazy[(pos<<1)|1]=lazy[pos];
        lazy[pos]=0;
    }
}

void up(int pos)
{
    if(tree[pos<<1]<tree[(pos<<1)|1])tree[pos]=tree[pos<<1];
    else tree[pos]=tree[(pos<<1)|1];
}

void change(int pos,int begin,int end,int l,int r,int x)
{
    if(l<=begin && end<=r)
    {
        if(tree[pos]<x)tree[pos]=x;
        if(lazy[pos]<x)lazy[pos]=x;
        return;
    }
    down(pos);
    int mid=(begin+end)>>1;
    if(l<mid)change(pos<<1,begin,mid,l,r,x);
    if(r>mid)change((pos<<1)|1,mid,end,l,r,x);
    up(pos);
}

bool find(int pos,int begin,int end,int l,int r,int x)
{
    if(l<=begin && end<=r)
    {
        //printf("%d,%d:%d\n",begin,end,tree[pos]);
        if(tree[pos]<x)return true;
        return false;
    }
    down(pos);
    int mid=(begin+end)>>1;
    if(l<mid && find(pos<<1,begin,mid,l,r,x))return true;
    if(r>mid && find((pos<<1)|1,mid,end,l,r,x))return true;
    return false;
}

void ini(int pos,int begin,int end)
{
    tree[pos]=lazy[pos]=0;
    if(begin+1==end)return;
    int mid=(begin+end)>>1;
    ini(pos<<1,begin,mid);
    ini((pos<<1)|1,mid,end);
}

int main()
{
    freopen("c-in.txt","r",stdin);
    freopen("c-out.txt","w",stdout);
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d",&N);
        m=0;
        S.clear();
        for(int i=0; i<N; i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
            for(int j=0; j<n; j++)
            {
                f[m].d=d+j*delta_d;
                f[m].l=w+j*delta_p;
                f[m].r=e+j*delta_p;
                f[m].h=s+j*delta_s;
                m++;
            }
        }
        ans=0;
        k=0;
        //for(int i=0;i<m;i++)
        //{
        //    printf("%d:%d,%d(%d)\n",f[i].d,f[i].l,f[i].r,f[i].h);
        //}
        for(int i=0;i<m;i++)
        {
            g[++k]=f[i].l;
            g[++k]=f[i].r;
        }
        //for(int i=1;i<=k;i++)
        //    printf("%d ",g[i]);
        //puts("");
        //puts("--------------");
        sort(g+1,g+k+1);
        r=k;
        k=1;
        for(int i=2; i<=r; i++)
            if(g[i]!=g[k])g[++k]=g[i];
        for(int i=1; i<=k; i++)
            S[g[i]]=i;
        //for(int i=1;i<=k;i++)
        //    printf("%d ",g[i]);
        //puts("");
        ini(1,1,k);
        for(int i=0;i<m;i++)
        {
            f[i].l=S[f[i].l];
            f[i].r=S[f[i].r];
        }
        sort(f,f+m);
        //for(int i=0;i<m;i++)
        //{
        //    printf("%d:%d,%d(%d)\n",f[i].d,f[i].l,f[i].r,f[i].h);
        //}
        now=0;
        while(now<m)
        {
            //printf("now1 %d\n",now);
            for(int i=now;i<m && f[i].d==f[now].d;i++)
            {
                //printf("find %d:%d,%d(%d)\n",f[i].d,f[i].l,f[i].r,f[i].h);
                if(find(1,1,k,f[i].l,f[i].r,f[i].h))
                {
                    ans++;
                }
            }
            for(int i=now;i<m && f[i].d==f[now].d;i++)
            {
                change(1,1,k,f[i].l,f[i].r,f[i].h);
                now=i;
            }
            now++;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
