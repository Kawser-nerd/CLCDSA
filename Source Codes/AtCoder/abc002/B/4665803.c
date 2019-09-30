#include<stdio.h>
#include<string.h>
char w[31];
int i,a;
int main(void){
    scanf("%s",w);
    a = strlen(w);
    for(i = 0;i < a;i++){
        if(w[i] != 0x61&&w[i]!=0x69&&w[i]!=0x75&&w[i]!=0x65&&w[i]!=0x6f){
printf("%c",w[i]);
        }
      
    }
  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",w);
     ^