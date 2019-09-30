#include <stdio.h>
#define MAX 100000

int main(){
  int i, j, N, M, high=0;
  long sum = 0;
  int l[MAX], r[MAX], s[MAX];
  long min[MAX];
  scanf("%d %d", &N, &M);
  for(i=1;i<=N;i++) min[MAX] = 0;
  for(i=1;i<=N;i++){
    scanf("%d %d %d", &l[i], &r[i], &s[i]);
    sum += s[i];
    for(j=l[i];j<=r[i];j++) min[j] += s[i];
  }
  for(i=1;i<=M;i++){
    if(high < sum - min[i]) high = sum - min[i];
  }
  printf("%d\n", high);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &l[i], &r[i], &s[i]);
     ^