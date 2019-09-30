#include <stdio.h>
#define maxn 100001

double p[maxn],p2[maxn];
double w[maxn],f[maxn];
int A,B;

void sol(int cas){
    int i,j,k;
    scanf("%d%d",&A,&B);
    p2[0]=1;
    for (i=0;i<A;i++){
        scanf("%lf",p+i);
        p2[i+1]=p2[i]*p[i];
    }
    double r = B+2;
    for (i=0;i<=A;i++){
        double t0 = p2[i]*(B-i+1)+(1-p2[i])*(B-i+1+B+1)+A-i;
        if (t0<r) r=t0;
    }
    printf("Case #%d: %.10lf\n",cas,r);
}

int main(){
    int T,cas;
    scanf("%d",&T);
    for (cas=1;cas<=T;cas++)
        sol(cas);
    return 0;
}

