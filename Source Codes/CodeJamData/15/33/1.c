#include <stdio.h>

long f[200],a[200];

int main() {
    long i,t,tt,ans,c,d,v;
    freopen("C-large.in.txt", "r", stdin);
    freopen("C-large.out.txt", "w", stdout);
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld%ld%ld",&c,&d,&v);
        for (i=0;i<d;i++){
            scanf("%ld",a+i+1);
        }
        a[0]=0;
        f[0]=0;
        ans=0;
        a[d+1]=v;
        for (i=0;i<=d;i++){
            f[i]=c*a[i];
            if (i>0)
                f[i]+=f[i-1];
            while (f[i]<(a[i+1]-1)){
                ans++;
                f[i]=c*(f[i]+1)+f[i];
            }
            if (f[i]>=v)
                break;
        }
        if (i>d){
            while (f[d]<v){
                ans++;
                f[d]+=c*(f[d]+1)+f[d];
            }
        }
        printf("Case #%ld: %ld\n",tt,ans);
    }
    return 0;
}
