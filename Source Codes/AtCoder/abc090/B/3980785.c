#include <stdio.h>

void kurai(int a[], int n){
  int i = 0;
  while(n > 0){
    a[i] = n % 10;
    n /= 10;
    i++;
  }
}

int main(void){
  int ary[5];
  int a, b;
  scanf("%d%d", &a, &b);
  int i;
  int count = 0;
  for(i = a; i <= b; i++){
    kurai(ary, i);
    if(ary[4] == ary[0] && ary[3] == ary[1]) count++;
  }
  printf("%d\n", count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^