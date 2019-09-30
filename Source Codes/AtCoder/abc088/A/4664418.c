#include<stdio.h>
int a,n;
int main(void){
    scanf("%d%d",&n,&a);
    if(a >= 499){
        printf("Yes");
    }else if(a >= n%500){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&a);
     ^