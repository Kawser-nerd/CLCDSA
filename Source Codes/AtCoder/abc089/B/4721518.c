#include<stdio.h>
int main()
{
  int n, x=0, i;
  char m;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%c", &m);
    if(m=='Y'){
      x+=1;
    }
  }
  if(x==0){
    printf("Three\n");
  }else{
    printf("Four\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &m);
     ^