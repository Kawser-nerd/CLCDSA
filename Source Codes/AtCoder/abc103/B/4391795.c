#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int main(void){
  char s[110],t[110];
  scanf("%s %s",s,t);
  int i,j,m=strlen(s);
  for(i=0;i<m;i++){
    if(strcmp(s,t)==0) {printf("Yes");return 0;}
    for(j=m;j>0;j--){
      t[j]=t[j-1];
    }
    t[0]=t[m];
    t[m]=0;
  }
  printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",s,t);
   ^