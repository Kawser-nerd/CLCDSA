#include <stdio.h>
int main(){
int N,a,b,c,d,i;
double e,max=0,sum;
scanf("%d",&N);
for(i=1;i<=N;i++){
    scanf("%d %d %d %d %lf",&a,&b,&c,&d,&e);
     sum= a+b+c+d+e*110/900;
    if (sum>max)max=sum;
}
printf("%f\n",max);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&N);
 ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %lf",&a,&b,&c,&d,&e);
     ^