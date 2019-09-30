#include <stdio.h>
int main(void){
    int n, i, j, cnt = 0;
    int a[100001] = {};
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &j);
        a[j]++;
        if(a[j]>1) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &j);
         ^