#include <stdio.h>
#include <math.h>

int N;
long ans;

long max(long a,long b){
  if(a > b){
    return a;
  }
  return b;
}

long min(long a,long b){
  if(a < b){
    return a;
  }
  return b;
}

void fanction(int N){
  for(int i = 1;i < 11;i++){
    ans += (N/(long)pow(10,i))*pow(10,i-1);
    ans += max(0,min(N%(long)pow(10,i)-pow(10,i-1),(long)pow(10,i-1)));
  }
}

int main(void){
  scanf("%d",&N);
  
  fanction(N+1);
  printf("%ld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^