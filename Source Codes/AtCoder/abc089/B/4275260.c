#include<stdio.h>
#include<string.h>

int main(){
  
  int i,j,k;
  char a;
  scanf("%d",&j);
  
  for(i=0;i<j;i++){
    scanf("%c ",&a);
    if((int)a == 89){
      puts("Four");
      return 0;
    }
  }
  
  puts("Three");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&j);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c ",&a);
     ^