#include<stdio.h>

int main(){
char s[3];
scanf ("%s", s);
if (s[0] != s[1] && s[1] != s[2] && s[2] != s[0]) {
    printf ("Yes");
}
else printf ("No");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%s", s);
 ^