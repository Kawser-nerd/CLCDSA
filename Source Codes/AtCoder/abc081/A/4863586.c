#include<stdio.h>
int main(){
   char a[3];
   int c=0;
   scanf("%s",a);
   for(int i=0;i<3;i++){
      if(a[i]=='1')c++;
   }
   printf("%d\n",c);
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",a);
    ^