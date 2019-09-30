#include <stdio.h>

int main(void){
    int n,m,i;
    int sum = 0;
    int t[101],p[101],x[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %d",&t[i]);
        sum = sum + t[i];
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&p[i],&x[i]);
    }
    for(i=0;i<m;i++){
        printf("%d\n",sum - t[p[i] - 1] + x[i]);
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf(" %d",&t[i]);
         ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&p[i],&x[i]);
         ^