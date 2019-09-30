#include<stdio.h>
int min(int a,int b){if(a<b){return a;}return b;}
main(){int n;scanf("%d",&n);printf("%d\n",(n/10)*100+min((n%10)*15,100));} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){int n;scanf("%d",&n);printf("%d\n",(n/10)*100+min((n%10)*15,100));}
 ^
./Main.c: In function ‘main’:
./Main.c:3:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 main(){int n;scanf("%d",&n);printf("%d\n",(n/10)*100+min((n%10)*15,100));}
              ^