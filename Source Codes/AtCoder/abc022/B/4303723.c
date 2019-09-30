#include<stdio.h>
int main(){
  int n,a[100000],b[100000]={},i,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(b[a[i]]) ans++;
    b[a[i]]++;
  }
  printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^