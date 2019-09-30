#include<stdio.h>

int main(){
  long n, count[1000002] = {0}, i, a, b, max = 0;
  
  scanf("%ld", &n);
  
  for (i = 0; i < n; i++){
    scanf("%ld %ld", &a, &b);
    count[a]++;
    count[b + 1]--;
  }
  for (i = 1; i < 1000001; i++){
    count[i] += count[i - 1];
  }
  for (i = 0; i < 1000001; i++){
    if(max < count[i]){
      max  =count[i];
    }
  }
  
  printf("%ld\n", max);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &a, &b);
     ^