#include <stdio.h>
int main(){
  int k;
  scanf("%d", &k);
  int a[k];
  int i;
  for(i=0;i<k;i++){
    scanf("%d", &a[i]);
  }
  if(a[k-1] != 2){
    puts("-1");
    return 0;
  }
  long long int max = 3, min = 2;
  for(i=k-2;i>=0;i--){
    if (max - max % a[i] < min){
      puts("-1");
      return 0;
    }else{
      max = max - max % a[i] + (long long int)(a[i] - 1);
      min = (min - 1) - (min - 1) % a[i] + (long long int)a[i];
    }
  }
  printf("%lld %lld\n", min, max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^