#include<stdio.h>
int main(void){
  int year,month,day;
  scanf("%d/%d/%d",&year,&month,&day);
  if(year!=2018){
    year=2018;
  }
  printf("%d/",year);
  if(month<10){
    printf("0");
  }
  printf("%d/",month);
  if(day<10){
    printf("0");
  }
  printf("%d",day);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d/%d/%d",&year,&month,&day);
   ^