#include <stdio.h>
int main(void){
    int d[7],j,ans=0;
    for (int i=0; i<7; i++){
        scanf("%d",&d[i]);
    }
    for (int i=0; i<7; i++){
        scanf("%d",&j);
        if (d[i]>j){
            ans+=d[i];
        } else {
            ans+=j;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&d[i]);
         ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&j);
         ^