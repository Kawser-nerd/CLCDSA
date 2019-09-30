#include <stdio.h>

int main(){
    int i,n,temp;
    int num[7];

    scanf("%d ",&n);

    for(i=1;i<7;i++){
        num[i]=i;
    }

    n%=30;
    
    for(i=0;i<n;i++){
        temp=num[i%5+1];
        num[i%5+1]=num[i%5+2];
        num[i%5+2]=temp;
    }

    for(i=1;i<7;i++){
        printf("%d",num[i]);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&n);
     ^