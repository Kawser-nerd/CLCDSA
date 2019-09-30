#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1000010;

inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();};
    while(isdigit(ch)){x=x*10+(ch-'0');ch=getchar();};x*=f;
}

struct edge {
    int x,y,nxt;
} E[MAXN<<1];
int head[MAXN],w[MAXN],ans[MAXN],n,m,tot=0;
struct node {
    int x,id;
} st[MAXN];

bool cmp(node A, node B) {
    return A.x<B.x;
}

inline void addedge(int x,int y) {
    E[++tot].x=x;
    E[tot].y=y;
    E[tot].nxt=head[x];
    head[x]=tot;
}

int main() {
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    memset(head,-1,sizeof head);
    read(n);
    for(int i=1;i<=n;i++) {
        read(w[i]);
        st[i].x=w[i];
        st[i].id=i;
    }
    for(int i=1,j,k;i<n;i++) {
        scanf("%d%d",&j,&k);
        addedge(j,k);
        addedge(k,j);
    }
    sort(st+1,st+1+n,cmp);
    for(int it=1;it<=n;it++) {
        int i=st[it].id;
        bool win=0;
        for(int j=head[i];~j;j=E[j].nxt) {
            int to=E[j].y;
            if(w[to]<w[i]) {
                win|=(ans[to]^1);
            }
        }
        ans[i]=win;
    }
    for(int i=1;i<=n;i++) {
        if(ans[i]){
            printf("%d ",i);
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}