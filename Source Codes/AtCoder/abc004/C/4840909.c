#include <stdio.h>
int main(void){
    int n,i,a,k[6];
    scanf("%d",&n);
    for(i=0;i<6;i++){
        k[i]=i+1;
    }
    for(i=0;i<n;i++){
        a=k[i%5];
        k[i%5]=k[i%5+1];
        k[i%5+1]=a;
    }
    for(i=0;i<6;i++){
        printf("%d",k[i]);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^