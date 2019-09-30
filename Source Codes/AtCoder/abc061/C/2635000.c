#include<stdio.h>
int main(void){
  long n,k,i,ho=0;
  scanf("%ld %ld",&n,&k);
  long a,b;
  long x[100000]={0};
  for(i=0;i<n;i++){
    scanf("%ld %ld",&a,&b);
    x[a-1]+=b;
  }
  for(i=0;i<100000;i++){
    ho+=x[i];
    if(ho>=k){
      break;
    }
  }
  printf("%ld",i+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&n,&k);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&a,&b);
     ^