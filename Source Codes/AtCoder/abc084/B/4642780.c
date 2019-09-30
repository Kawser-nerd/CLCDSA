#include <stdio.h>
int main (){
int i=0,k=0,a,b;
char s[20];
  scanf ("%d%d%s",&a,&b,s);
  for (i=0;s[i]!=0;i++){
  if (i!=a && s[i]<'9'+1 && s[i]>'0'-1){
  ;
  }
  else if (i==a && s[i]=='-'){
    ;
  }
    else {
      k++;
    break;
    }
  }
  if (k==0){
  printf ("Yes");
  }
  else {
  printf ("No");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%s",&a,&b,s);
   ^