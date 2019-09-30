#include <stdio.h>

char *S[]={"No","Yes"};
char f;

int n, m, o;
int main(){
  scanf("%d", &n);
  m=n;
  while(m){
  	o+=m%10;
  	m=m/10;
  }
  f = (n%o==0);
  puts(S[f]);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^