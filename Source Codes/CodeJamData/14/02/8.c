#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps 1e-8
int t,T;
double C,F,X;
double bST(double l,double r){
    double m;
    int j;
    double buildTime;
    double ans=r;
    while(l+eps<=r){
        m = (l+r)/2;
        if(m*2.0>=X){
            if(m<ans)ans=m;
            r = m-eps;
            continue;
        }
        for(j=0,buildTime=0.0;;++j){
            buildTime += C/(2.0+F*(j));
            if( (buildTime>=m)||(m-buildTime)*(2.0+F*(j+1))>=X ){
                break;
            }
        }
        if(buildTime>=m){
            l=m+eps;
        }else {
            if(m<ans)ans=m;
            r = m-eps;
        }
    }
    return ans;
}

int main(){
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%lf %lf %lf",&C,&F,&X);
        printf("Case #%d: %.7lf\n",t,bST(0.0,X/2.0));

    }

    return 0;
}
