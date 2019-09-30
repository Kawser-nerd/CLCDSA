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
  int N,a,b,count=0;
  scanf("%d %d %d",&N,&a,&b);
  for(int k=1;k<=N;k++){
    int keta = log10(k)+1;int tmp = k;int stock=0;
    //printf("%d:keta:%d\n",k,keta);
    int num[keta];
    for(int i=0;i<keta;i++){
      num[i]=tmp%10;
      tmp = (tmp-num[i])/10;
    }
    for(int j=0;j<keta;j++)stock += num[j];
      //printf("%d\n",stock);
    if(stock >= a && stock <= b){
      count+=k;//printf("%d\n",k );
    }
  }
  printf("%d",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&a,&b);
   ^