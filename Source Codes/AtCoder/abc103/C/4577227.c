#include<stdio.h>
int main(){int n;scanf("%d",&n);long long sum=0;for(int i=0;i<n;i++)  {int t;scanf("%d",&t); sum+=t-1;}printf("%lld\n",sum);return 0;} ./Main.c: In function ‘main’:
./Main.c:2:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(){int n;scanf("%d",&n);long long sum=0;for(int i=0;i<n;i++)  {int t;scanf("%d",&t); sum+=t-1;}printf("%lld\n",sum);return 0;}
                  ^
./Main.c:2:78: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(){int n;scanf("%d",&n);long long sum=0;for(int i=0;i<n;i++)  {int t;scanf("%d",&t); sum+=t-1;}printf("%lld\n",sum);return 0;}
                                                                              ^