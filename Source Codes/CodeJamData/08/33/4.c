#include <stdio.h>
#include <stdlib.h>
#define MX 600000
int N;
unsigned long long int n, m, X, Y, Z, totsol;
unsigned long long int A[MX];
unsigned long long int in[MX];
unsigned long long int sol[MX];
int main()
{
    int i, j, cs;
    scanf("%d",&N);
    for(cs=1; cs<=N; cs++)
    {
     scanf("%llu%llu%llu%llu%llu", &n, &m, &X, &Y, &Z);
     for(i=0; i<m; i++)
     scanf("%llu",&A[i]);
     for(i=0; i<n; i++)
     {
      in[i] = A[i%m];
      A[i%m] = ((X*A[i%m])%Z + (Y*(i+1))%Z)%Z;
     } 
     totsol = 0;
     for(i=(n-1); i>=0; i--)
     {
      sol[i] = 1;
      for(j=(n-1); j>i; j--)
      {
       if(in[j] > in[i])
       sol[i] = (sol[i]+sol[j])%1000000007;
      }
      totsol = (totsol+sol[i])%1000000007;
     }
     printf("Case #%d: %llu\n", cs, totsol);
    }
    return 0;
}
