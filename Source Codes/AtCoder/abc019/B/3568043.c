#include<stdio.h>

int main(){
char s[1001];
int i,j=0;
char tmp;
scanf("%s",s);
tmp=s[0];
for(i=0;s[i]!=0;i++){
if(tmp!=s[i]){
printf("%c%d",tmp,j);
j=1;
tmp=s[i];
}else j++;
}
printf("%c%d\n",tmp,j);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",s);
 ^