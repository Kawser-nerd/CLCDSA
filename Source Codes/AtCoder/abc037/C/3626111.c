#include<stdio.h>

int main(){
int n,m,i;
long long unsigned ans=0;
long long bubunwa[100000]={0},a[100000];
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)scanf("%ld",&a[i]);
for(i=0;i<m;i++)bubunwa[0]+=a[i];
for(i=m;i<n;i++){
bubunwa[i-m+1]+=a[i]+bubunwa[i-m];
bubunwa[i-m+1]-=a[i-m];
}
for(i=0;i<n;i++)ans+=bubunwa[i];
printf("%llu\n",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:23: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
 for(i=0;i<n;i++)scanf("%ld",&a[i]);
                       ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d",&n,&m);
 ^
./Main.c:8:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 for(i=0;i<n;i++)scanf("%ld",&a[i]);
                 ^