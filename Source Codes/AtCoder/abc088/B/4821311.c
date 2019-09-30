#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void sort(int *, int);

int main(){
  int n, a[MAX], alice, bob;
  int i;
  scanf("%d", &n);
  if(n < 1 || MAX < n)
    return 1;

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    if( a[i] < 1 || 100 < a[i])
      return 1;
  }
  sort(a, n);
  alice = 0;
  bob = 0;

  for(i = 0; i < n; i++){
    if(!(i%2)){
      alice += a[i];
    }else{
      bob += a[i];
    }
  }
  printf("%d\n", alice - bob);
  
  return 0;
}

void
sort(int *array, int length){
  int i, j;
  int temp;
  
  for(i = 0; i < length -1; i++){
    for(j = length -2; i <= j; j--){
      if (array[j] < array[j+1]){
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^