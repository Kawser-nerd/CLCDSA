#include<stdio.h>
#define MAX 100005

int main(){
  char s[MAX],*p;
  fread(s,sizeof(char),MAX,stdin);
  p=s;
  
  while(*p!='\n'){
    //  printf("%c , %c , %c\n",*p,*(p+1),*(p+2));
    if(*p==*(p+1)){
      printf("%d %d\n",&*p-s+1,&*p-s+2);
      return 0;
    }
    if(*p==*(p+2)){
      printf("%d %d\n",&*p-s+1,&*p-s+3);
      return 0;
    }
    
    *p++;
  }
  puts("-1 -1");
} ./Main.c: In function ‘main’:
./Main.c:12:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
       printf("%d %d\n",&*p-s+1,&*p-s+2);
              ^
./Main.c:12:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long int’ [-Wformat=]
./Main.c:16:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
       printf("%d %d\n",&*p-s+1,&*p-s+3);
              ^
./Main.c:16:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long int’ [-Wformat=]
./Main.c:6:3: warning: ignoring return value of ‘fread’, declared with attribute warn_unused_result [-Wunused-result]
   fread(s,sizeof(char),MAX,stdin);
   ^