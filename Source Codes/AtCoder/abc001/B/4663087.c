#include<stdio.h>
int a;
int main(void){
    scanf("%d",&a);
    if(a<100){
        printf("00");
    }else if(a>=100&&a<=5000){
       if(a/100<=9){
           printf("0%d",a/100);
       }else{
           printf("%d",a/100);
       }
    }else if(a>=6000&&a<=30000){
        printf("%d",a/1000+50);
    }else if(a>=35000&&a<=70000){
        printf("%d",((a/1000)-30)/5+80);
    }else if(a>70000){
        printf("89");
    }
  printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^