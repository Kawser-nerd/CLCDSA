#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(void){
  int n,i,j;
  char s[100][11];
  scanf("%d",&n);
  scanf("%s",s[0]);
  for(i=1;i<n;i++){
    scanf("%s",s[i]);
    int l=strlen(s[i-1]);
    for(j=0;j<i;j++){
      if(strcmp(s[i],s[j])==0) {printf("No");return 0;}
    }
    if(s[i-1][l-1]!=s[i][0]) {printf("No");return 0;}
  }
  printf("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[0]);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^