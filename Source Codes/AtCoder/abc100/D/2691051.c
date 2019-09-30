#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const void *a,const void *b){
  long *A = (long *)a;
  long *B = (long *)b;
  if (*A > *B) return -1;
  if (*A < *B) return 1;
  return 0;
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    long long x[N],y[N],z[N];
    long long sum=0,max=-1;
    int i,j,k,l;
    for(i=0;i<N;i++){
        scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
    }

    for(i=-1;i<=1;i+=2){
        for(j=-1;j<=1;j+=2){
            for(k=-1;k<=1;k+=2){
                sum = 0;
                long long a[N];
                for(l=0;l<N;l++){
                    a[l] = i*x[l] + j*y[l] + k*z[l];
                }
                qsort(a,N,sizeof(long long),comp);
                for(l=0;l<M;l++){
                    sum += a[l];
                }
                if( sum > max ){
                    max = sum;
                }
            }
        }
    }

    printf("%lld\n",max);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&N,&M);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
         ^