#include<stdio.h>
#include<stdlib.h>
int main(void){
  int a, b, c, d;
  if(scanf("%d %d %d %d", &a, &b, &c, &d)==1);
  printf("%s\n",(abs(a-b)<=d&&abs(b-c)<=d||abs(a-c)<=d)?"Yes":"No");
  return 0;
}