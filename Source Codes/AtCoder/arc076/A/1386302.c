#include<stdio.h>
    long long int N,M;
     
    long long int modfact(long long int n)
    {
      long long int result=1;
      if(n == 0 || n == 1)
        return 1;
      else
        for(;n>0;n=n-1){
          result = (result *n) % 1000000007;
        }
      return result;
    }
    int main()
    {
      long long int tmp;
      scanf("%lld %lld",&N,&M);
      if(N < M){
        tmp = N;
        N = M;
        M = tmp;
      }
      if(N - M == 0 || N-M == 1){
      if((N+M)%2)
        printf("%lld\n",(modfact(N)*modfact(M))%1000000007);
      else
        printf("%lld\n",(2*modfact(N)*modfact(M))%1000000007);
      }else
        printf("%d\n",0);
      return 0;
    } ./Main.c: In function ‘main’:
./Main.c:18:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%lld %lld",&N,&M);
       ^