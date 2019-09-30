#include<stdio.h>
long int mini(long int a,long int b){
  if(a>b) return b;
  return a;
}

int main(void){
  long int ans=1000000000,cnt=0,n,i;
  scanf("%ld",&n);
  long int a[n];
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
  }
  for(i=0;i<n;i++){
    cnt=0;
    while(a[i]){
      if(a[i]%2==1) break;
      a[i]/=2;
      cnt++;
    }
    ans=mini(ans,cnt);
  }
  printf("%ld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^