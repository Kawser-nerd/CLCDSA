#include <string.h>
 
int main()
{
  char s[11], out[11]={'\0'};
  scanf("%s", s);
  int n = strlen(s);
  for(int i=0; i<n; i++){
    int m = strlen(out);
    if(s[i] == 'B') out[m-1]='\0';
    else out[m]=s[i];
  }
  printf("%s", out);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%s", s);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:13:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%s", out);
   ^
./Main.c:13:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’