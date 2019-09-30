#include <stdio.h>
#include <math.h>

int main(void){
    int n,a,b,l;
    scanf("%d%d%d%d",&n,&a,&b,&l);

    double len=l;
    double t=len/a;
    for(int i=0; i<n; i++){
        len=t*b;
        t=len/a;
    }
    if(a==b)printf("0\n");
    else printf("%lf\n",len);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&n,&a,&b,&l);
     ^