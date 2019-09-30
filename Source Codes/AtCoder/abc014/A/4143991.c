#include<stdio.h>

int main(){
    int a,b,c;
    int sa;

    scanf("%d",&a);
    scanf("%d",&b);

    if(a==b){
        printf("0\n");
    }else{
        c = a / b;
        sa = b*(c+1)-a;
        printf("%d\n",sa);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^