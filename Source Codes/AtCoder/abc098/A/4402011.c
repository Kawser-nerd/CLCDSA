#include<stdio.h>

int main(void)
{
    int a,b,c,d,e,f;
    scanf("%d %d",&a,&b);
    c=a+b;
    d=a-b;
    e=a*b;
    if(c<d){
        f=c;
        c=d;
        d=f;
    }
    if(d<e){
        f=d;
        d=e;
        e=f;
    }
    if(c<d){
        f=c;
        c=d;
        d=f;
    }
    printf("%d",c);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^