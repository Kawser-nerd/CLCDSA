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
  int a,b,count=0;
  scanf("%d %d",&a,&b);
  if(a == b){
    printf("%d",0);return 0;
  }
  for(int i=a;i<=b;i++){
    int flag=0;
    int keta = log10(i);int tmp = i;
    int num[keta];
    for(int j=0;j<=keta;j++){
      num[j]=tmp%10;
      tmp = (tmp-num[j])/10;
    }
    for(int k=0;k<keta;k++){
      if((k == keta-k || k+1 == keta - k)&&flag==0){
        count++;break;
      }
      if(num[k] != num[keta-k])flag=1;
    }
  }
  printf("%d",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^