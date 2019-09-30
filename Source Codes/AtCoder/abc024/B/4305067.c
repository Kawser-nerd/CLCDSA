#include<stdio.h>
int main(){
  int n,t,a[100000],i;
  scanf("%d%d",&n,&t);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int sum=t;
  for(i=1;i<n;i++){
    if(a[i]-a[i-1]<t){
      sum+=a[i]-a[i-1];
    }
    else {
      sum+=t;
    }
  }
  printf("%d\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&t);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^