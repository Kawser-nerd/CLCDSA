#include<stdio.h>
    int main(void){
     int a,b,c[100],k,i,j=0;
    scanf("%d%d%d",&a,&b,&k);
    if(a>b) { a=a+b; b=a-b; a=a-b;}
    for(i=1;i<=a;i++){
    if((a%i==0)&&(b%i==0))  {c[j]=i; j++;}}
    printf("%d",c[j-k]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&k);
     ^