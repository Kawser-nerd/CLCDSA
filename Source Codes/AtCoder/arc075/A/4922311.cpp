#include <iostream>
#include <vector>
int main(void){
  short i, j, n, sum = 0, ans = 0; scanf("%hd", &n);
  std::vector<short> A(n);
  for(i = 0; i < n; i++){
    scanf("\n%hd", &A[i]);
    sum += A[i];
  }
  std::vector<bool> KingCrimson(sum + 1, false);
  KingCrimson[0] = true;
  sum = 0;
  for(i = 0; i < n; i++){
    for(j = sum; j >= 0; j--){
      if(KingCrimson[j]) KingCrimson[j + A[i]] = true;
    }
    sum += A[i];
  }
  for(short i = 0; i <= sum; i++) if(KingCrimson[i] and i % 10 != 0) ans = i;
  printf("%hd\n", ans);
  return 0;
}