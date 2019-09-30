#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long N;

  scanf("%ld", &N);

  if(N % 30 == 1){
    printf("213456\n");
  }else if(N % 30 == 2){
    printf("231456\n");
  }else if(N % 30 == 3){
    printf("234156\n");
  }else if(N % 30 == 4){
    printf("234516\n");
  }else if(N % 30 == 5){
    printf("234561\n");
  }else if(N % 30 == 6){
    printf("324561\n");
  }else if(N % 30 == 7){
    printf("342561\n");
  }else if(N % 30 == 8){
    printf("345261\n");
  }else if(N % 30 == 9){
    printf("345621\n");
  }else if(N % 30 == 10){
    printf("345612\n");
  }else if(N % 30 == 11){
    printf("435612\n");
  }else if(N % 30 == 12){
    printf("453612\n");
  }else if(N % 30 == 13){
    printf("456312\n");
  }else if(N % 30 == 14){
    printf("456132\n");
  }else if(N % 30 == 15){
    printf("456123\n");
  }else if(N % 30 == 16){
    printf("546123\n");
  }else if(N % 30 == 17){
    printf("564123\n");
  }else if(N % 30 == 18){
    printf("561423\n");
  }else if(N % 30 == 19){
    printf("561243\n");
  }else if(N % 30 == 20){
    printf("561234\n");
  }else if(N % 30 == 21){
    printf("651234\n");
  }else if(N % 30 == 22){
    printf("615234\n");
  }else if(N % 30 == 23){
    printf("612534\n");
  }else if(N % 30 == 24){
    printf("612354\n");
  }else if(N % 30 == 25){
    printf("612345\n");
  }else if(N % 30 == 26){
    printf("162345\n");
  }else if(N % 30 == 27){
    printf("126345\n");
  }else if(N % 30 == 28){
    printf("123645\n");
  }else if(N % 30 == 29){
    printf("123465\n");
  }else if(N % 30 == 0){
    printf("123456\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &N);
   ^