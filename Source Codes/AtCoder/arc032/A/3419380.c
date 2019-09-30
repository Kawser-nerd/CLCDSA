#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    if (n==1){
        printf("BOWWOW\n");
        return 0;
    }
    n=(n+1)*n/2;
    for (int i=2; i<n; i++){
        if (n%i==0){
            printf("BOWWOW\n");
            return 0;
        }
    }
    printf("WANWAN\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^