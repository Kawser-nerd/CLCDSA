#include<stdio.h>

int main(void){
    long long n,a[64],i,j,jud,rw=0,h;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);rw+=a[i];
    }
    for(i=rw-100000;i<=rw;i++){
        if(i<0){continue;}
        h=0;
        for(j=1;j<=n;j++){
            jud=i+a[j];h+=(jud/(n+1));
            if(jud%(n+1) == n){h++;}
        }
        if(h>i){continue;}
        printf("%lld\n",i);break;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);rw+=a[i];
         ^