#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  return *(long*)a-*(long*)b;
}

int main(void){
  int N;
  scanf("%d",&N);

  int a[N];
  for(int i = 0;i < N;i++){
    scanf("%d",&a[i]);
    while(a[i]%2 == 0) a[i] /= 2;
  }
  qsort(a,N,sizeof(int),compare_int);

  int cnt = 1;
  int past = a[0];
  for(int i = 1;i < N;i++){
    if(a[i] != past){
      past = a[i];
      cnt++;
    }
  }

  printf("%d\n",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^