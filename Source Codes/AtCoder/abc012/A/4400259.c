#include<stdio.h>
main(){int n,m;scanf("%d%d",&n,&m);printf("%d %d\n",m,n);} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){int n,m;scanf("%d%d",&n,&m);printf("%d %d\n",m,n);}
 ^
./Main.c: In function ‘main’:
./Main.c:2:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 main(){int n,m;scanf("%d%d",&n,&m);printf("%d %d\n",m,n);}
                ^