#include<stdio.h>

int main(void){
  int n,i,flag,cnt=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  while(1){
    flag=0;
    for(i=0;i<n;i++){
      if(a[i]%2==0){
        a[i] = a[i]/2;
        cnt++;
        flag=1;
      }
    }
    if(flag==0){
      break;
    }
  }
  
  printf("%d\n",cnt);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^