#include<stdio.h>
int main(){int n,m;scanf("%d%d",&n,&m);printf("%d\n",((m-1)>=1?(m-1):2));return 0;} ./Main.c: In function ‘main’:
./Main.c:2:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(){int n,m;scanf("%d%d",&n,&m);printf("%d\n",((m-1)>=1?(m-1):2));return 0;}
                    ^