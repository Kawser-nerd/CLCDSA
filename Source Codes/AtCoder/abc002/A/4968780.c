#include<stdio.h>
int main(void){
    int a,b,c;
    scanf("%d %d",&a,&b);
    c = a;
    if (b > a){
        c = b;
    }
    printf("%d\n",c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^