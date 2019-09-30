#include<stdio.h>
#include<math.h>

int main(){

  long long n;
  scanf("%lld",&n);

  long long a[n];

  for(long long i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }

  long long b0=0;
  long long b1=0;
  long long b2=0;

  for(long long i=0;i<n;i++){
    if(a[i]%4==0){
      b2++;
    }
    else if(a[i]%2==0){
      b1++;
    }
    else{
      b0++;
    }
  }

  if(b1==0){
    if(b2+1>=b0){
      printf("Yes\n");
    }
    else{
      printf("No\n");
    }
  }
  else{
    if(b2>=b0){
      printf("Yes\n");
    }
    else{
      printf("No\n");
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a[i]);
     ^