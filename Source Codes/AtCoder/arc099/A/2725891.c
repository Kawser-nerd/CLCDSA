#include<stdio.h>

int main(){
  int n,k,a[100000],mina=100001,minp=0,ans=0,cnt=0;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(mina>a[i]){
      mina=a[i];
      minp=i;
    }
  }
  ans=k;
  cnt=1;
  while(ans<n){
    ans+=k-1;
    cnt++;
  }
  printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^