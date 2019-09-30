#include <stdio.h>
int main (){
char s[1001];
  scanf ("%s",s);
  int i,k=1;
  for (i=0;s[i]!=0;i++){
  if (s[i]==s[i+1]){
    k++;
  }
    else {
    printf ("%c%d",s[i],k);
      k=1;
    }
  }
  printf ("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s",s);
   ^