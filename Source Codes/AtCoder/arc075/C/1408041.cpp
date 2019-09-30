#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int size=2e6+10;
const int INF=1e9;
typedef long long LL;
//LL tree[size];
LL a[size];
LL b[size];
//int lowbit(int x)
//{
//    return x&(-x);
//}
//void update(int x)
//{
//    while(x<size)
//    {
//        tree[x]+=1;
//        x+=lowbit(x);
//    }
//}
//LL ask(int x)
//{
//    LL sum=0;
//    while(x)
//    {
//       sum+=tree[x];
//       x-=lowbit(x);
//    }
//    return sum;
//}
struct node
{
    int l,r;
    int sum;
}tree[size];
//void build(int l,int r,int rt)
//{
//    int mid=(l+r)>>1;
//    tree[rt].l=l,tree[rt].r=r,tree[rt].sum=0;
//    if(l==r) return ;
//    build(l,mid,rt*2);
//    build(mid+1,r,rt*2+1);
//}
//void pushdown(int rt)
//{
//    tree[rt].sum=tree[rt*2].sum+tree[rt*2+1].sum;
//}
void update(int num,int x)
{
    if(tree[num].l==tree[num].r)
    {
        tree[num].sum++;
        return ;
    }
    int mid=(tree[num].l+tree[num].r)/2;
    if(x<=mid)
        update(2*num,x);
    else update(2*num+1,x);
    tree[num].sum++;
}
//void update(int pos,int l,int r,int rt)
//{
//    if(l==r)
//    {
//        tree[rt].sum++; return ;
//    }
//    int mid=(l+r)>>1;
//    if(pos<=mid) update(pos,l,mid,rt*2);
//    else update(pos,mid+1,r,rt*2+1);
//    pushdown(rt);
//}
//LL ask(int l,int r,int rt)
//{
////    printf("l=%d r=%d\n ",l,r);
//    if(l>r) return 0;
//    if(l==tree[rt].l&&r==tree[rt].r)
//        return tree[rt].sum;
//   LL sum=0;
//   int mid=(l+r)>>1;
//   if(l<=mid) sum+=ask(l,mid,rt*2);
//   if(r>mid) sum+=ask(mid+1,r,rt*2+1);
//   return sum;
//}
void build(int num,int l,int r)
{
    if(l==r)
    {
        tree[num].l=tree[num].r=l;
//        fa[r]=num;
        tree[num].sum=0;
        return ;
    }
    tree[num].l=l; tree[num].r=r; tree[num].sum=0;
    int mid=(l+r)/2;
    build(2*num,l,mid);
    build(2*num+1,mid+1,r);
}
int ask(int l,int r,int rt)
{
    if(tree[rt].l==l&&tree[rt].r==r)
    {
        return tree[rt].sum;
    }
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(l>mid)
    {
         return ask(l,r,2*rt+1);
    }
    else if(r<=mid)
    {
        return ask(l,r,2*rt);
    }
    else
    {
        return ask(l,mid,2*rt)+ask(mid+1,r,2*rt+1);
    }
}
int main()
{
   int n;LL p;
   while(scanf("%d%lld",&n,&p)!=EOF)
   {
      // memset(tree,0,sizeof(tree));
     build(1,1,n+1);
     LL ans=0;
     for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
     for(int i=1;i<=n;i++)
     {
         b[i]-=p;
         b[i]=b[i]+b[i-1];
         if(b[i]>=0) ans++;
         a[i-1]=b[i];
     }
     sort(a,a+n);
     int cnt=unique(a,a+n)-a;
//     build(1,n,1);
     for(int i=1;i<=n;i++)
     {
          int temp=lower_bound(a,a+cnt,b[i])-a+1;
         int pri=ask(1,temp,1);
        ans+=pri;
//          printf("pri=%d\n",pri);
          update(1,temp);
     }
//     out(1,n,1);
     printf("%lld\n",ans);
   }
}