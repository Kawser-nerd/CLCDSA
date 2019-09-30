#include <stdio.h>
int main(void){
    int n,max=0,min=0;
    scanf("%d",&n);
    int d[n];
    for (int i=0; i<n; i++){
        scanf("%d",&d[i]);
        max+=d[i];
    }
    for (int i=0; i<n; i++){
        min=d[i]>(max-d[i])?(d[i]*2-max):min;
    }
    printf("%d\n%d\n",max,min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&d[i]);
         ^