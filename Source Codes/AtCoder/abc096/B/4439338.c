#include <stdio.h>

int main(void){
    
    int a,b,c,k,w;
    scanf("%d %d %d %d",&a,&b,&c,&k);
    
    if(a<c){
        w=a;
        a=c;
        c=w;
    }
    if(a<b){
        w=b;
        b=a;
        a=w;
    }
    if(b<c){
        w=b;
        b=c;
        c=w;
    }
    for(int i=0; i<k; i++)
        a*=2;

    printf("%d",a+b+c);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&a,&b,&c,&k);
     ^