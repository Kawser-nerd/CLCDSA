#include<stdio.h>

int main(){

   int n,i;
   int y=0;
   char s[101];

   scanf("%d",&n);
   for(i=0;i<n;i++)
      scanf("%c",&s[i]);

   for(i=0;i<n;i++)
      if(s[i]=='Y')
         y++;

   if(y==0) printf("Three");
   else printf("Four");
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&n);
    ^
./Main.c:11:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%c",&s[i]);
       ^