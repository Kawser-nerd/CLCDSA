#include<stdio.h>

int main(void){
    int n,k;
    scanf("%d %d\n",&n,&k);
    if(n%k==0){
        printf("%d\n",0);
    }
    else{
        printf("%d\n",1);
    }

} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n",&n,&k);
     ^