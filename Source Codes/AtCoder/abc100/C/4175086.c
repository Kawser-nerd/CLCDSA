#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int a, int b){
  return a >= b ? a : b;
}
int min(int a, int b){
  return b >= a ? a : b;
}
int factorial(int n) {
    if (n > 0) return n*factorial(n - 1);
		else return 1;
}
int compare_up_int(const void *a, const void *b){
   return *(int*)a - *(int*)b;
}
int compare_up_int_l(const void *a, const void *b){
   return *(long int*)a - *(long int*)b;
}
int compare_down_int(const void *a, const void *b){
   return *(int*)b - *(int*)a;
}
int compare_down_int_l(const void *a, const void *b){
   return *(long int*)b - *(long int*)a;
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
  int N,count=0;
  scanf("%d",&N);
  long int num[N];
  for(int i=0;i<N;i++) scanf("%ld ",&num[i]);
  for(int i=0;i<N;i++){
    while(1){
      if(num[i]%2==0){
        count++;num[i]/=2;
      }
      else break;
    }
  }
  printf("%d",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:42:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i=0;i<N;i++) scanf("%ld ",&num[i]);
                        ^