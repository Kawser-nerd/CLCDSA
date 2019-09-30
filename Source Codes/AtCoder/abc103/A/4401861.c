#include<stdio.h>

int main(void)
{
    int a,b,c,d;
    scanf("%d %d %d",&a,&b,&c);
    if(b<c){
        d=b;
        b=c;
        c=d;
    }
    if (a<b){
        d=a;
        a=b;
        b=d;
    }
    if(b<c){
        d=b;
        b=c;
        c=d;
    }
    printf("%d",a-c);
    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&c);
     ^