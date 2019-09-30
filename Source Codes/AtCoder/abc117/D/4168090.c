#include<stdio.h>
int main(void) {
  int N,i,j,sum[40];
  long K,A[100000],B[100000],ans=0;
  long long ans2=0;
  for(i=0;i<40;i++)sum[i]=0;
  scanf("%d %ld",&N,&K);
  for(i=0;i<N;i++) {
    scanf("%ld",&A[i]);
    B[i] = A[i];
  }
  for(i=0;i<N;i++)for(j=0;j<40;j++) {
    sum[j]+=A[i]%2;
    A[i] = A[i] >> 1;
  }
  for(i=39;i>-1;i--)if(sum[i]*2<N)if(pow(2.0,i)+ans<=K)ans+=(long)pow(2.0,i);
  for(i=0;i<N;i++)ans2+=ans^B[i];
  printf("%lld\n",ans2);
} ./Main.c: In function ‘main’:
./Main.c:16:38: warning: implicit declaration of function ‘pow’ [-Wimplicit-function-declaration]
   for(i=39;i>-1;i--)if(sum[i]*2<N)if(pow(2.0,i)+ans<=K)ans+=(long)pow(2.0,i);
                                      ^
./Main.c:16:38: warning: incompatible implicit declaration of built-in function ‘pow’
./Main.c:16:38: note: include ‘<math.h>’ or provide a declaration of ‘pow’
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %ld",&N,&K);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&A[i]);
     ^