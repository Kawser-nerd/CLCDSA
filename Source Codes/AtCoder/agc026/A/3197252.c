#include<stdio.h>

int main(){
  int n = 0 ;
  int i ; 
  int count = 0 ;
  scanf("%d",&n);

  int a[n] ;
  for (i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }


  for (i = 0 ; i < n - 1 ; i++ ){
    if (a[i] == a[i+1]){
      count++;
      i++;

    }
  }
  printf("%d\n",count);
  return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^