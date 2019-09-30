#include<stdio.h>
 
long long maxim(long long a,long long b){if(a<b){return b;}return a;}
long long rou(long long a,long long b){
if(a%b){return (a/b)+1;}else{return a/b;}
}
 
int main(void){
long long n,a,b,h[131072],i,need;
long long max=10000000000,min=1,t;
scanf("%lld%lld%lld",&n,&a,&b);
for(i = 1;i <= n;i++){scanf("%lld",&h[i]);}
while(max >= min){
need = 0;
t = (max+min)/2;
for(i = 1;i <= n;i++){if(h[i]-(b*t)>0){need+=rou(h[i]-(b*t),a-b);}}
if(need <= t){max = t-1;}else{min = t+1;}
}
printf("%lld\n",min);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%lld%lld%lld",&n,&a,&b);
 ^
./Main.c:12:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 for(i = 1;i <= n;i++){scanf("%lld",&h[i]);}
                       ^