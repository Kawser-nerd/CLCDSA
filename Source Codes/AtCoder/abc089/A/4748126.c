#include<stdio.h>
int main(){
    int n,out;
    scanf("%d",&n);

    if(n==0 || n==1 || n==2){
        out=0;
    }else {
        out=n/3;
    }
    printf("%d",out);
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^