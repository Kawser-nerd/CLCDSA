#include<stdio.h>

int main(){
  int i,a[200001]={},n,p,cnt=1,max=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&p);
    a[p]=i;
  }
  for(i=1;i<n;i++){
    if(a[i]<a[i+1])
      cnt++;
    else{
      if(max<cnt)
        max=cnt;
      cnt=1;
    }
  }
  if(max<cnt)
    max=cnt;
  printf("%d\n",n-max);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&p);
     ^