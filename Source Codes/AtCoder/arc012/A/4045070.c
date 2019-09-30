#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char day[16];

  scanf("%s", day);

  if(day[0] == 'S'){
    printf("0\n");
  }else if(day[0] == 'M'){
    printf("5\n");
  }else if(day[0] == 'W'){
    printf("3\n");
  }else if(day[0] == 'F'){
    printf("1\n");
  }else if(day[1] == 'u'){
    printf("4\n");
  }else{
    printf("2\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", day);
   ^