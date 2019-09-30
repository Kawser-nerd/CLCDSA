#include<stdio.h>
int N, M;
char c, O[51];
int main(){
  c=getchar();
  while(c!=10){
    O[N]=c;
    c=getchar(); N++;
  }
  c=getchar();
  while(c!=10){
    putchar(O[M]);
    putchar(c);
    c=getchar(); M++;
  }
  if(N!=M){
    putchar(O[N-1]);
  }
  putchar(10);
}