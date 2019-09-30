#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIGITS 4

int getSum(int);

int
main(){
  int n, a, b, temp, sum = 0;
  int i;
  scanf("%d %d %d", &n, &a, &b);
  if(n < 1 || 10000 < n || a < 1 || 36 < b || b < a )
    return 1;

  for(i = 0; i <= n; i++){
    temp = getSum(i);
    if ( a <= temp && temp <= b)
      sum += i;
  }
  printf("%d\n", sum);
  return 0;
}

int
getSum(int input){
  int i, ret = 0;
  for( i = 0; i < MAXDIGITS + 1; i++){
    ret += input % 10;
    input = input / 10;
    if(!input)
      break;
  }
  return ret;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &n, &a, &b);
   ^