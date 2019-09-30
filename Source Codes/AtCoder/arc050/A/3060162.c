#include<stdio.h>
int main()
{
char c1,c2;
scanf("%c %c",&c1,&c2);
if(c2==(c1-'A'+'a'))
printf("Yes\n");
else
printf("No\n");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%c %c",&c1,&c2);
 ^