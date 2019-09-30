#include<stdio.h>
#include<string.h>

int main(void){
  char s[200],t[200];
  int n,i,j,l,r;
  gets(s);
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&l,&r);
    strcpy(t,s);
    for(j=0;j<r-l+1;j++){
      s[j+l-1]=t[r-j-1];
    }
  }
  printf("%s\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(s);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&l,&r);
     ^
/tmp/ccT2nLdF.o: In function `main':
Main.c:(.text.startup+0x23): warning: the `gets' function is dangerous and should not be used.