#include<stdio.h>
char c;
char d[4];
int main(void){
  while((c=getchar())!=10){
    if(c=='N'){
      d[0]=1;
    }else if(c=='W'){
      d[1]=1;
    }else if(c=='S'){
      d[2]=1;
    }else{
      d[3]=1;
    }
  }
  if((d[0]^d[2]) || (d[1]^d[3])){
    puts("No");
  }else{
    puts("Yes");
  }
}