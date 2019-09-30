#include <stdio.h>
int main(){
char a[50],b[50];
	scanf("%s%s",&a,&b);
  if (strlen(a)>strlen(b)){
	printf ("%s\n",&a);
  }
  else{
  printf ("%s\n",&b);
  }
  return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
  scanf("%s%s",&a,&b);
        ^
./Main.c:4:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[50]’ [-Wformat=]
./Main.c:5:7: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   if (strlen(a)>strlen(b)){
       ^
./Main.c:5:7: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:5:7: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:6:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
  printf ("%s\n",&a);
          ^
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
   printf ("%s\n",&b);
           ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result...