#include<stdio.h>
#include<string.h>

int main(){
  int i,j,k;
  int w,h;
  char S[256];
  scanf("%d %d",&h,&w);
  
  for(i=0;i<w+2;i++)
    printf("#");
  puts("");
  
  for(i=0;i<h;i++){
    scanf("%s",S);
    printf("#%s#\n",S);
  }

  for(i=0;i<w+2;i++)
    printf("#");
  puts("");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",S);
     ^