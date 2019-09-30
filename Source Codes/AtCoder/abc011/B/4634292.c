#include <stdio.h>
int main (){
char s[13];
scanf ("%s",s);
for (int i;s[i]!=0;i++){
if (i==0 && s[i]<'z'+1 && s[i]>'a'-1) s[i]=s[i]+'A'-'a';
else if(i!=0 && (s[i]>'z' || s[i]<'a')) s[i]=s[i]+'a'-'A';
printf ("%c",s[i]);
}
printf ("\n");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s",s);
 ^