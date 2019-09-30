#include <stdio.h>
int main(void){
int a;
  scanf("%d",&a);
  if(a<=111){printf("111");}
  else if(112<=a&&a<=222){printf("222");}
    else  if(223<=a&&a<=333){printf("333");}
    else  if(334<=a&&a<=444){printf("444");}
    else  if(445<=a&&a<=555){printf("555");}
    else  if(556<=a&&a<=666){printf("666");}
    else  if(667<=a&&a<=777){printf("777");}
    else  if(778<=a&&a<=888){printf("888");}
    else  if(889<=a&&a<=999){printf("999");}
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^