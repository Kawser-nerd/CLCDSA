#include<stdio.h>

int main(){
    int n,h=0,m=0,s=0;
    scanf("%d",&n);

    if(3600<=n){
        h = n / 3600;
        n = n - 3600*h;
    }
    if(60<=n){
        m = n / 60;
        s = n - m*60;
    }
    if(60>n){
        s = n;
    }
    printf("%02d:%02d:%02d\n",h,m,s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^