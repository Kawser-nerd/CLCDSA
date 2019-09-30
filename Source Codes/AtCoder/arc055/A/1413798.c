#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int i;
    if(n!=0)
    printf("1");
    for(i=0;i<n-1;i++){
        printf("0");
    }
    printf("7\n");
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^