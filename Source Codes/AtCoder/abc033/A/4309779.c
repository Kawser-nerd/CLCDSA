#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int i,a[4];
  for(i=0;i<4;i++){
    a[i]=getchar()-'0';
    if(a[0]!=(a[i])){
      printf("DIFFERENT\n");
      return 0;
    }
  }
  printf("SAME\n");
  return 0;
}