#include<stdio.h>
char *s[2] = {"YES", "NO"};
char c[6], f, i;
int main(){
  c[0] = getchar();
  c[1] = getchar();
  c[2] = getchar();
  getchar();
  c[3] = getchar();
  c[4] = getchar();
  c[5] = getchar();
  for(i=0; i<3; i++){
    if(c[i] != c[5-i]){f=1;}
  }
  puts(s[f]);
}