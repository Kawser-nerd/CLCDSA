#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++)  {int t;scanf("%d",&t); sum+=t-1;}
    printf("%lld\n",sum);return 0;
} ./Main.c: In function ‘main’:
./Main.c:3:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^
./Main.c:5:34: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<n;i++)  {int t;scanf("%d",&t); sum+=t-1;}
                                  ^