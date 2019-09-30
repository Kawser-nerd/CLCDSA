#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  return *(long*)a-*(long*)b;
}

int main(void){
  long N;
  long ans = 0;
  scanf("%ld",&N);

  long long A[N];
  for(int i = 0;i < N;i++) scanf("%lld",&A[i]);

  qsort(A,N,sizeof(long),compare_int);

  for(int i = 0;i < N;i++){
    int sample = A[i];
    int counter = 0;
    while(1){
      if(i+counter >= N) break;
      if(A[i+counter] != sample) break;
      counter++;
    }
    if(counter%2 != 0) ans++;
    i += counter-1;
  }

  printf("%ld",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&N);
   ^
./Main.c:14:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%lld",&A[i]);
                            ^