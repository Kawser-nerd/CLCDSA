#include<stdio.h>
char *P[]={"Impossible","Possible"};
char c;
char h, w, a;
int main(void){
  h=getchar()-'0';
  getchar();
  w=getchar()-'0';
  getchar();
  while((c=getchar())!=EOF){
    if(c=='#'){a++;}
  }
  puts(P[h+w==a+1]);
}