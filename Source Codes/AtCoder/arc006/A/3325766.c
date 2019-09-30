#include <stdio.h>
#define N 20

int main(void){
  int b,ct=0,v=0,i,j,e[N]={0},l[N]={0};
  for(i=0;i<6;i++){
    scanf("%d",&e[i]);
  }
  scanf("%d",&b);
  for(i=0;i<6;i++){
    scanf("%d",&l[i]);
  }
  for(j=0;j<6;j++){
    for(i=0;i<6;i++){
      if(e[j]==l[i]){
        ct+=1;
      }
      if(l[i]==b){
        v+=1;
      }
    }
  }
  switch(ct){
    case 6:printf("1"); break;
    case 5:if(v!=0){
      printf("2");
    }else{
      printf("3");
    }
    break;
    case 4:printf("4"); break;
    case 3:printf("5"); break;
    default :printf("0");
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&e[i]);
     ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^