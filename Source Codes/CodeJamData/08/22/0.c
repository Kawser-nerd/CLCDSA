#include<stdio.h>
#include<string.h>

#define MAXN 1000000

char b[MAXN+1];
int p[80000];
int np;

void init() { 
    int i,j; 
    for(i=2;i<MAXN;i++) { 
        if (!b[i]) p[np++]=i; 
        for(j=0;j<np && i*p[j]<MAXN;j++) { 
            b[i*p[j]]=1; 
            if (i%p[j]==0) break; 
        }
    } 
} 

int u[MAXN+1];
int cnt;
int top(int k) {
    return u[k]<0?k:(u[k]=top(u[k]));
}
void uu(int tt1,int tt2) {
    int t1=top(tt1),t2=top(tt2);
    if (t1!=t2) u[t2]=t1,cnt--;
}

int main() {
    int N,cs=0;
    int i;
    long long a,b,pp,j;

    init();
    for(scanf("%d",&N);N--;) {
        scanf("%lld %lld %lld",&a,&b,&pp);
        memset(u,0xff,sizeof(u));
        cnt=b-a+1;
        for(i=0;i<np;i++)
            if (p[i]>=pp) {
                for(j=(a+p[i]-1)/p[i]*p[i];j+p[i]<=b;j+=p[i])
                    uu(j-a,j+p[i]-a);
            }
        printf("Case #%d: %d\n",++cs,cnt);
    }
    return 0;
}
