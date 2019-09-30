#include<stdio.h>

int main(void){
 
  int n;
  scanf("%d", &n);
  
  int a[100000];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  int count=0;
  
  for(int i=0;i<n;i++){
   	if(a[i]%2 == 1)count++; 
  }
  
  if(count%2==0){
    printf("YES");
  }else{
  	printf("NO"); 
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^