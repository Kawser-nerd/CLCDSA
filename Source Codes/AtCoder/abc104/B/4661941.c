#include<stdio.h>
char *P[]={"WA","AC"};
char f;

char c;
char C;
char n;
int main(){
  if(getchar()=='A'){f=1;}
  else{f=0;}
  while(f && (c=getchar())!=10){
    n++;
    if(c=='C' && C==0){
      C=n;
    }else if(c<'a' || 'z'<c){
      f=0;
    }
  }
  f = f && 2<=C && C<=n-1;
  puts(P[f]);
}