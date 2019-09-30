#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    double ans=0,tmp,min;
    int n;
    scanf("%d",&n);
    double s[n],t[n],v[n];
    for (int i=0; i<n; i++){
        double p;
        scanf("%lf",&p);
        s[i]=t[i-1],t[i]=t[i-1]+p;
    }
    for (int i=0; i<n; i++){
        scanf("%lf",&v[i]);
    }
    for (int i=0; i<t[n-1]*2; i++){
        min=fmin((double)i/2,(t[n-1]*2-(double)i)/2);
        for (int j=0; j<n; j++){
            if (i<s[j]*2){
                tmp=v[j]+(s[j]*2-(double)i)/2;
            } else if (s[j]*2<=i && t[j]*2>i){
                tmp=v[j];
            } else {
                tmp=v[j]+((double)i-t[j]*2)/2;
            }
            if (min>tmp){
                min=tmp;
            }
        }
        ans+=min;
    }
    printf("%lf\n",ans/2);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf",&p);
         ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf",&v[i]);
         ^