#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d",&N);

    int sum=0;
    int a,ct=0;
    for(int i=0;i<N;i++){
        scanf("%d",&a);
        sum+=a;
        if(a!=0) ct++;
    }
    int ans;
    if(sum%ct==0) ans=sum/ct;
    else ans=sum/ct+1;
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a);
         ^