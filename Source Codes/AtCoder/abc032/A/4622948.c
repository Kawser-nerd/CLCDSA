#include <stdio.h>
int main(){
int a,b,c,i;
scanf("%d%d%d",&a,&b,&c);
for(i=c; i<=c+a*b; i++){

if(i%a==0&&i%b==0){

printf("%d\n",i);

break;

}

}



return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d",&a,&b,&c);
 ^