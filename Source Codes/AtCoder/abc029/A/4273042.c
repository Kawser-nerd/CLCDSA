#include <stdio.h>
int main(){
char w[10];
scanf("%s", &w);
printf("%s",w);
printf("s\n");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
 scanf("%s", &w);
       ^
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s", &w);
 ^