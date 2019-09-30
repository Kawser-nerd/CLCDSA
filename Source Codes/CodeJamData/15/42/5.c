#include <stdio.h>
#include "stdlib.h"
#include "math.h"

long double pip[110][2];
long n;

int comp(const void *a,const void *b){
    long double t;
    t=((long double *)a)[1]-((long double *)b)[1];
    if (t>0)
        return 1;
    else if (t<0)
        return -1;
    else
        return 0;
}

int main() {
    long i,j,k,t,tt,flag;
    long double v,x,totf,totdel;
    freopen("B-small-attempt1.in.txt", "r", stdin);
    freopen("B-small-attempt1.out.txt", "w", stdout);

    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld%Lf%Lf",&n,&v,&x);
        totf=0;
        totdel=0;
        for (i=0;i<n;i++){
            scanf("%Lf%Lf",pip[i],pip[i]+1);
            totf+=pip[i][0];
            pip[i][1]-=x;
            totdel+=pip[i][0]*pip[i][1];
        }
        qsort(pip, n, sizeof(long double)*2, comp);
        flag=1;
        if (totdel>0.0000000001){
            for (i=n-1;i>=0&&fabs(totdel)>0.000000001;i--){
                if (pip[i][0]*pip[i][1]>totdel){
                    totf-=totdel/pip[i][1];
                    totdel=0;
                    break;
                }
                else {
                    totdel-=pip[i][0]*pip[i][1];
                    totf-=pip[i][0];
                }
            }
            if (totf<0.0000000001)
                flag=0;
        }
        else if (totdel<-0.0000000001){
            for (i=0;i<n&&fabs(totdel)>0.000000001;i++){
                if (pip[i][0]*pip[i][1]<totdel){
                    totf-=totdel/pip[i][1];
                    totdel=0;
                    break;
                }
                else {
                    totdel-=pip[i][0]*pip[i][1];
                    totf-=pip[i][0];
                }
            }
            if (totf<0.0000000001)
                flag=0;
        }
        printf("Case #%ld: ",tt);
        if (flag)
            printf("%0.7Lf\n",v/totf);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
