#include<stdio.h>
int main(){
  int n,i;
  char c;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%c",&c);
    if(c=='Y'){
      c=0;
      break;
    }
  }
  puts(c?"Three":"Four");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&c);
     ^