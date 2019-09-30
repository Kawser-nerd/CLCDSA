#include <stdio.h>
int main(void){
    int a,b,x;
    scanf("%d%d%d",&a,&b,&x);
    if(a==x) {printf("YES"); return 0;}
    else if(a>x||a+b<x) {printf("NO"); return 0;}
    else if(a<x){
        if(a+b>=x) printf("YES"); return 0;
    }
    else printf("NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&x);
     ^