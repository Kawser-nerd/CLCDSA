#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
double car[123][2];
double a;
int n,A;
double d;
int main(){
    int Case = 0;
    int t;
    int i,j,k;
    double ans;
    double temp;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %d %d",&d,&n,&A);
        for(i=0;i<n;++i){
            scanf("%lf %lf",&car[i][0],&car[i][1]);
        }
        --n;
        printf("Case #%d:\n",++Case);
        for(i=0;i<A;++i){
            scanf("%lf",&a);
            ans = sqrt(2*d/a);
            temp = (d-car[n-1][1])/((car[n][1]-car[n-1][1])/(car[n][0]-car[n-1][0]));
            if(ans < temp)ans = temp;
            printf("%lf\n",ans);
        }

    }
    return 0;
}
