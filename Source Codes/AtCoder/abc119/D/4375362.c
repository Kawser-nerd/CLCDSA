#include <stdio.h>
#include <stdlib.h>
#define INF 900000000000000000

long long min(long long a,long long b){
  if(a < b){
    return a;
  }
  return b;
}

long long max(long long a,long long b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int A,B,Q;
  long long lezinzya,rizinzya;
  long long letera,ritera;
  scanf("%d%d%d",&A,&B,&Q);

  long long s[A+2],t[B+2],x;
  for(int i = 1;i <= A;i++) scanf("%lld",&s[i]);
  for(int i = 1;i <= B;i++) scanf("%lld",&t[i]);
  s[0] = 0; t[0] = 0;
  s[A+1] = INF;
  t[B+1] = INF;

  for(int k = 0;k < Q;k++){
    long long ans;
    scanf("%lld",&x);
    int le = 0;
    int ri = A+1;
    int mid = (ri+le)/2;
    while(ri-le > 1){
      mid = (ri+le)/2;
      if(x < s[mid])
        ri = mid;
      else
        le = mid;
    }
    if(s[le] == 0) lezinzya = INF;
    else lezinzya = llabs(x-s[le]);
    if(s[ri] == INF) rizinzya = INF;
    else rizinzya = llabs(x-s[ri]);

    le = 0;
    ri = B+1;
    mid = (ri+le)/2;
    while(ri-le > 1){
      mid = (ri+le)/2;
      if(x < t[mid])
        ri = mid;
      else
        le = mid;
    }
    if(t[le] == 0) letera = INF;
    else letera = llabs(x-t[le]);
    if(t[ri] == INF) ritera = INF;
    else ritera = llabs(x-t[ri]);

    ans = min(max(lezinzya,letera),max(rizinzya,ritera));
    ans = min(ans,min(lezinzya*2+ritera,rizinzya*2+letera));
    ans = min(ans,min(letera*2+rizinzya,ritera*2+lezinzya));
    printf("%lld\n",ans);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&Q);
   ^
./Main.c:26:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 1;i <= A;i++) scanf("%lld",&s[i]);
                             ^
./Main.c:27:29: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 1;i <= B;i++) scanf("%lld",&t[i]);
                             ^
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&x);
     ^