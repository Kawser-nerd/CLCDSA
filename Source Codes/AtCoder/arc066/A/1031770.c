#include<stdio.h>
#define X 1000000007

int res(int k){
    int i,r = 1;
    for(i = k;i >= 1;i--){r*=2;r%=X;}
    return r;
}

int main(void){
    int n,a[131072]={0},i,d,r;
    scanf("%d",&n);
    for(i = 1;i <= n;i++){scanf("%d",&d);a[d]++;}
    if(n%2){
        if(a[0] != 1){printf("0\n");return 0;}
        for(i = 2;i <= (n-1);i+=2){
            if(a[i] != 2){printf("0\n");return 0;}
        }
        r = res((n-1)/2);
        printf("%d\n",r);
    }
    else{
        for(i = 1;i <= (n-1);i+=2){
            if(a[i] != 2){printf("0\n");return 0;}
        }
        r = res((n/2));
        printf("%d\n",r);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:13:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i = 1;i <= n;i++){scanf("%d",&d);a[d]++;}
                           ^