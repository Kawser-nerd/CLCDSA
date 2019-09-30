#include<stdio.h>
int main(void){
  int i=0,j=0;
  char s[11];
  char t[11];
  scanf("%s",&s);
  while(s[i]!='\0'){
    if(s[i]!='B'){
      t[j]=s[i];
      j++;
    }else{
      if(j<1){
        j=j-j;
      }else{
        j=j-1;
      }
    }
    i++;
  }
  t[j]='\0';
  printf("%s\n",t);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[11]’ [-Wformat=]
   scanf("%s",&s);
         ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&s);
   ^