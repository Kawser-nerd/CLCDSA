#include <stdio.h>
int main (){
char s[100000];
scanf ("%s",s);
  if (strlen(s)%2==0){
for (int i=0;i<strlen(s)/2;i++){
printf ("%c",s[2*i]);
}
  }
  else{
  for (int i=0;i<(1+strlen(s))/2;i++){
printf ("%c",s[2*i]);
}
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:7: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   if (strlen(s)%2==0){
       ^
./Main.c:5:7: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:5:7: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s",s);
 ^