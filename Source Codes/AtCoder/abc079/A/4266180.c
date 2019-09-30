#include<stdio.h>

int main(void){
  int a[4],i;
  for(i=0;i<4;i++){
    a[i] = getchar()-'0';
  }
  if(a[1]!=a[2]){
  }else{
    if((a[0]==a[1]) || (a[2]==a[3])){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}