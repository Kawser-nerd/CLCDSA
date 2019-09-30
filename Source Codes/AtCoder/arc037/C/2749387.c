#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}

long long a[32768],b[32768],n;

long long pat(long long x){
  long long i,st,fi,te,r=0;
  for(i=0;i<n;i++){
    st=0;fi=n-1;
    while(st<=fi){
      te=(st+fi)/2;
      if(a[i]*b[te]>=x){fi=te-1;}else{st=te+1;}
    }
    r+=(n-st);
  }
  return r;
}

int main(void){
  long long i,k;
  long long st=0,fi=llinf,te;
  scanf("%lld%lld",&n,&k);
  k=(n*n)-k+1;
  for(i=0;i<n;i++){scanf("%lld",&a[i]);}
  for(i=0;i<n;i++){scanf("%lld",&b[i]);}
  qsort(a,n,sizeof(long long),llsortfncsj);
  qsort(b,n,sizeof(long long),llsortfncsj);
  while(st<=fi){
    te=(st+fi)/2;
    //if(fi<100){printf("<%lld %lld %lld %lld>\n",st,fi,te,pat(te));}
    if(pat(te)<k){fi=te-1;}else{st=te+1;}
  }
  printf("%lld\n",fi);
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&n,&k);
   ^
./Main.c:32:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++){scanf("%lld",&a[i]);}
                    ^
./Main.c:33:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++){scanf("%lld",&b[i]);}
                    ^