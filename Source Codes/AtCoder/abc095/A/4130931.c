#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
  char s[3];
  int i;
  int bill=700;
  
  for(i=0;i<3;i++){
    s[i] = getchar();
  }
  
  for(i=0;i<3;i++){
    if(s[i]=='o'){
      bill += 100;
    }
  }
  
  printf("%d\n",bill);
  
  return 0;
}