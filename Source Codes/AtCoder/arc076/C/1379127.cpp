// if both points not on the edge, it doesn't matter

// what if both points on the same edge

#include <stdio.h>
#include <algorithm>
#include <map>

int t1,t2,t3,t4,t5;

int r,c,n;
int xa[100005];
int ya[100005];     // int 'y1' redeclared as ...
int xb[100005];
int yb[100005];

std::map<int,int> e;

int st[200005];
int st2=0;

int get(int u,int v)
{
    if (u==0) return v+1;
    if (v==c) return 300000000+u;
    if (u==r) return 600000000-v;
    if (v==0) return 900000000-u;
    return -1;
}

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d%d%d",&r,&c,&n);
    for (int i=0; i<n; i++) scanf("%d%d%d%d",xa+i,ya+i,xb+i,yb+i);
    // do matching bracket stuff
    for (int i=0; i<n; i++) {
        t1=get(xa[i],ya[i]);
        t2=get(xb[i],yb[i]);
        //printf("%d %d\n",t1,t2);
        if (t1==-1 || t2==-1) continue;
        e[t1]=i;
        e[t2]=i;
    }
    for (std::pair<int,int> p:e) {
        if (st2 && st[st2-1]==p.second) st2--;
        else st[st2++]=p.second;
    }
    printf(st2?"NO":"YES");
}