#include<stdio.h>
int main(void){
  int odd=0 ,n,i;
  scanf("%d",&n);
  int a[n];
  for(i = 0; i < n ;i++){
    scanf("%d",&a[i]);
    if(a[i] % 2 != 0){
      odd ++;
    }
  }
  if(odd % 2 == 0){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^