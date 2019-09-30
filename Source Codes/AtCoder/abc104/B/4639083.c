#include <stdio.h>
#include <string.h>
int main (){
char s[11];
int i,k=0,l=0,m=0,n=0;
scanf ("%s",s);
if (s[0]=='A'){
l++;
}
for (i=0;s[i]!=0;i++){
n++;
if (s[i] < 'z'+1 && s[i] > 'a'-1){
m++;
}
}
for (i=2;i<strlen(s)-1;i++){
if (s[i]=='C'){
k++;
}
}
if (k==1 && l==1 && m==n-2){
printf ("AC");
}
  else {
  printf ("WA");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s",s);
 ^