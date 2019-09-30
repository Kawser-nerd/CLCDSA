#include<stdio.h>
#include<string.h>

int main(void){
  char o[50],e[50];
  int len,i,j,k;
  scanf("%s",o);
  scanf("%s",e);
  len = strlen(o)+strlen(e);
  j=k=0;
  for(i=0;i<len;i++){
    if(i%2==0){
      printf("%c",o[j]);
      j++;
    }else{
      printf("%c",e[k]);
      k++;
    }
  }
  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",o);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",e);
   ^