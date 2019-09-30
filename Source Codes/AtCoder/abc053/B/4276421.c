#include<stdio.h>
#include<string.h>
int main(){
  char str[300000];
  scanf("%s",str);
  
  int i,j,k=1,max=0;
  for(i=0;i<strlen(str);i++){
    if(str[i]=='A'){
      j=i;
      break;
  }
  }
  for(i=strlen(str)-1;i!=0;i--){
    if(str[i]=='Z'){
      k=i;
      break;
  }
  }
  
  printf("%d\n",k-j+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^