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
  int A,B,K;
  scanf("%d %d %d",&A,&B,&K);
  if(B-A >= 2*K){
    for(int i=0;i<K;i++){
      printf("%d\n",A+i);
    }
    for(int i=K-1;i>=0;i--){
      printf("%d\n",B-i);
    }
    return 0;
  }
  else{
    for(int i=A;i<B+1;i++)printf("%d\n",i);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&K);
   ^