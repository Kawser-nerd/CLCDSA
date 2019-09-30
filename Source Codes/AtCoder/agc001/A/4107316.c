#include<stdio.h>

int main(){

  int N;

  // input N
  scanf("%d",&N);

  if (N < 0 || N > 100 ){
    return 1;
  }

  int a[2*N];
  // input Li until 2N
  for (int i=0; i < 2*N; i++ ){
    scanf("%d",&a[i]);
    if (a[i] < 0 || a[i] > 100 ){
      return 1;
    }
  }

  // sort a[] from smallest to largest

  int tmp;
  for (int i=0; i<2*N; ++i) {
    for (int j=i+1; j<2*N; ++j) {
      if (a[i] > a[j]) {
        tmp =  a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }


  int sum=0;
  // calculate sum
  for (int i=0; i < 2*N; i++ ){
    if ( i%2==0){
    //printf ("%d ",a[i]);
    sum+=a[i];
    }
  }

  printf("%d\n", sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^