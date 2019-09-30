#include <stdio.h>
int main(){
char s[116];
for (int i=0;i<116;i++){
scanf("%c",&s[i]);
}
printf("A%cC\n",s[8]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%c",&s[i]);
 ^