#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
  return a >= b ? a : b;
}
int min(int a, int b){
  return b >= a ? a : b;
}
int sei(int a){
  return a>0 ? a : 0;
}
int factorial(int n) {
    if (n > 0) return n*factorial(n - 1);
		else return 1;
}
int compare_up_int(const void *a, const void *b){
   return *(int*)a - *(int*)b;
}
int compare_down_int(const void *a, const void *b){
   return *(int*)b - *(int*)a;
}
int euclid(int a, int b){
  if(a < b){int tmp = a;a = b;b = tmp;}
  int r = a % b;
  if(r < 0) r += b;
  while(r != 0){
    a = b;b = r;r = a % b;
    if(r < 0) r += b;
  }
  return b;
}

int main(){
  int N,D,X,count=0;
  scanf("%d",&N);
  scanf("%d %d",&D,&X);
  int num[N];
  for(int i=0;i<N;i++) scanf("%d",&num[i]);
  for(int i=0;i<N;i++){
    for(int j=0;j<100;j++){
      if(1 + j*num[i] <= D)count ++;
    }
  }
  printf("%d",X + count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&D,&X);
   ^
./Main.c:42:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<N;i++) scanf("%d",&num[i]);
                        ^