#include <stdio.h>
int main()
{
  int N, M, i, a, b;
  scanf("%d %d", &N, &M);
  int arr[N];
  for (i=0; i<N; i++) arr[i]=0;
  for (i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    arr[a-1]+=1;
    arr[b-1]+=1;
  }
  for (i=0; i<N; i++) printf("%d\n", arr[i]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^