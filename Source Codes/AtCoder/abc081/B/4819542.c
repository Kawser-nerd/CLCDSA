#include <stdio.h>
#include <stdlib.h>

int isEven(int *, int);
void devTwo(int *, int);

int
main(){
  int i, n, a[200], count;
  scanf("%d", &n);
  if(n < 0 || 200 < n)
    return 1;
  
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    if(a[i] < 1 || 1000000000 < a[i])
      return 1;
  }
  count = 0;
  while(!isEven(a, n)){
    devTwo(a, n);
    count += 1;
  }

  printf("%d\n",count);

  return 0;
}

/*
 * even 0
 * odd 1
 */
int isEven(int *array, int argc){
  int i;
  for (i = 0; i < argc; i++){
    if ( (array[i])%2 || !(array[i]))
      return 1;
  }
  return 0;
}


void devTwo(int *array, int argc){
  int i;
  for (i = 0; i < argc; i++){
    array[i] = array[i] / 2;
  }
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^