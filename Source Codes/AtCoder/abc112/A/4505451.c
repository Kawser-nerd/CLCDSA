#include <stdio.h>

int main(){
    int n,a,b;
    scanf("%d",&n);
    if(n==1) printf("Hello World\n");
    else {
        scanf("%d %d",&a,&b);
        printf("%d",a+b);
    }   
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^