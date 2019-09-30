#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int bignumber(int a, int b){
    if(a>b){
        return(a);
    } else {
        return(b);
    }
}

int smallnumnber(int a, int b){
    if(a<b){
        return(a);
    } else {
        return(b);
    }
}

int greatestcommondivisor(int a,int b){
    int m,n,gcdans;
    m=bignumber(a,b);
    n=smallnumnber(a,b);
    if(n==0){
        gcdans=m;
    } else {
        gcdans=greatestcommondivisor(n,m%n);
    }
    return (gcdans) ;
}

int main(void){
    int n,k,max=0,gcd;
    scanf("%d%d",&n,&k);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(max<a[i]){
            max=a[i];
        }
        if (i==0){
            gcd=a[i];
        } else {
            gcd=greatestcommondivisor(gcd,a[i]);
        }
    }
    if (k<=max && k%gcd==0){
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:40:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^