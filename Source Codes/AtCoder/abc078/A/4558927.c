#include<stdio.h>
int main(void){
char x,y;
scanf("%s %s",&x,&y);
if(x<y){
printf("<\n");
}else if(x>y){
printf(">\n");
}else{
printf("=\n");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s %s",&x,&y);
 ^