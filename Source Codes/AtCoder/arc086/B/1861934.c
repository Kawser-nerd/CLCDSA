#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,i,a,max=0,mi=1;
  scanf("%d",&n);
  printf("%d\n",n*2);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(abs(a)>abs(max)){
      max=a;
      mi=i+1;
    }
  }
  if(max<0){
    printf("%d %d\n%d %d\n",mi,n,mi,n);
    for(i=1;i<n;i++)printf("%d %d\n%d %d\n",n-i+1,n-i,n-i+1,n-i);
  }
  else{
    printf("%d %d\n%d %d\n",mi,1,mi,1);
    for(i=1;i<n;i++)printf("%d %d\n%d %d\n",i,i+1,i,i+1);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^