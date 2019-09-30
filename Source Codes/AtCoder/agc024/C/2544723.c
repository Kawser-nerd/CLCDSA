#include<stdio.h>
int main(){
  long a[200000],cnt=0;
  long i,n;
  scanf("%ld",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
  }
  if(a[n-1]>n-1){
    printf("-1\n");
    return 0;
  }
  else
    cnt=a[n-1];
  for(i=n-2;i>=0;i--){
    if(a[i+1]>a[i]+1||a[i]>i){
      printf("-1\n");
      return 0;
    }
    else if(a[i+1]!=a[i]+1)
      cnt+=a[i];
  }
  printf("%ld\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^