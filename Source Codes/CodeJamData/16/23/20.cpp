#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int hash[10];
int len;
struct node
{
	node *next;
	int where;
}*first[10001],c[10001];
int test,tota,totb,n,v[10001],l;
map<string,int> a,b;
bool bo[10001];
void makelist(int x,int y)
{
	c[++l].where=y;
	c[l].next=first[x];
	first[x]=&c[l];
}
bool match(int now)
{
	bo[now]=true;
	for (node *x=first[now];x;x=x->next)
    if (!v[x->where]||(!bo[v[x->where]]&&match(v[x->where])))
    {
        v[x->where]=now;
        return true;
    }
	return false;
}
void work(int idx)
{
    printf("Case #%d: ",idx);
    scanf("%d", &n);
    memset(first,0,sizeof(first));
    l=0;
    tota=totb=0;
    a.clear();
    b.clear();
    for (int i=1;i<=n;i++)
    {
        int x,y;
        string str;
        cin>>str;
        if (a.find(str)==a.end())
            a[str]=++tota;
        x=a[str];
        cin>>str;
        if (b.find(str)==b.end())
            b[str]=++totb;
        y=b[str];
        makelist(x,y);
    }
    int ans=tota+totb;
    memset(v,0,sizeof(v));
    for (int i=1;i<=tota;i++)
    {
        memset(bo,false,sizeof(bo));
        if (match(i))
            ans--;
    }
    printf("%d\n",n-ans);
}
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    work(i);
}


