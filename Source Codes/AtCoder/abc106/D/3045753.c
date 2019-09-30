#include <stdio.h>
int main(){int i,p,q,N,M,Q,a[501][501]={};scanf("%d %d %d",&N,&M,&Q);for(i=M;i--;){scanf("%d %d",&p,&q);a[p][q]++;}for(p=1;p<=N;p++)for(q=1;q<=N;q++)a[p][q]+=a[p][q-1];for(p=1;p<=N;p++)for(q=1;q<=N;q++)a[p][q]+=a[p-1][q];for(i=Q;i--;scanf("%d %d",&p,&q)+printf("%d\n",a[q][q]-a[--p][q]-a[q][p]+a[p][p]));return 0;} ./Main.c: In function ‘main’:
./Main.c:2:43: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(){int i,p,q,N,M,Q,a[501][501]={};scanf("%d %d %d",&N,&M,&Q);for(i=M;i--;){scanf("%d %d",&p,&q);a[p][q]++;}for(p=1;p<=N;p++)for(q=1;q<=N;q++)a[p][q]+=a[p][q-1];for(p=1;p<=N;p++)for(q=1;q<=N;q++)a[p][q]+=a[p-1][q];for(i=Q;i--;scanf("%d %d",&p,&q)+printf("%d\n",a[q][q]-a[--p][q]-a[q][p]+a[p][p]));return 0;}
                                           ^
./Main.c:2:84: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(){int i,p,q,N,M,Q,a[501][501]={};scanf("%d %d %d",&N,&M,&Q);for(i=M;i--;){scanf("%d %d",&p,&q);a[p][q]++;}for(p=1;p<=N;p++)for(q=1;q<=N;q++)a[p][q]+=a[p][q-1];for(p=1;p<=N;p++)for(q=1;q<=N;q++)a[p][q]+=a[p-1][q];for(i=Q;i--;scanf("%d %d",&p,&q)+printf("%d\n",a[q][q]-a[--p][q]-a[q][p]+a[p][p]));return 0;}
                                                                               ...