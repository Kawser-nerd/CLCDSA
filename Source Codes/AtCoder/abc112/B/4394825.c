#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, tl;
    scanf("%d%d",&n,&tl);
    int c[n], t[n];
    int min = 1001;
    for(int i=0; i<n; i++){
        scanf("%d%d",&c[i], &t[i]);
        if(t[i] <= tl && c[i] < min){
            min = c[i];
        }
    }
    if(min != 1001){
        printf("%d\n", min);
    }else{
        printf("TLE\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&tl);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&c[i], &t[i]);
         ^