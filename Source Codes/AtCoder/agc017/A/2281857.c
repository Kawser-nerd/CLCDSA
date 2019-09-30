#include<stdio.h>
#include<math.h>

int main(void) {
  int N, P;
  scanf("%d %d", &N, &P);
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A[i] = A[i]%2;
  }
  
  int cnt0 = 0;
  int cnt1 = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == 0) cnt0++;
    else cnt1++;
  }
  
  
  long long int ans = 0;
  if (P == 1) {
    if (cnt1 == 0) printf("%d", 0);
    else {
      ans = pow(2, cnt0 +(cnt1-1) )*1;
      printf("%lld", ans);
    }
  } else {
    if (cnt0 == 0) {
      ans = pow(2, cnt1-1)*1;
      printf("%lld", ans);
    } else if (cnt1 == 0){
      ans = pow(2, N);
      printf("%lld", ans);
    }else {
      ans = pow(2, cnt0 + (cnt1-1) )*1;
      printf("%lld", ans);
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &P);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &A[i]);
     ^