#include<stdio.h>
char f;
char *s[2] = {"No", "Yes"};
char c[4];
int main(){
  c[0]=getchar();
  c[1]=getchar();
  c[2]=getchar();
  c[3]=getchar();
  f = c[1]==c[2] && (c[0]==c[1] || c[2]==c[3]);
  puts(s[f]);
}