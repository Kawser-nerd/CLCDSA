#include<stdio.h>

int sum(int *a,int n){
  int sum=0,i;
  for(i=0;i<n;i++){
    sum+=a[i];
  }
  return sum;
}
int main(){
  int n,a[100],i,ave,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  if(sum(a,n)%n){
    puts("-1");
    return 0;
  }
  else {
    ave=sum(a,n)/n;
    for(i=1;i<=n;i++){
      if(sum(a,i)-ave*i){
        ans++;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^