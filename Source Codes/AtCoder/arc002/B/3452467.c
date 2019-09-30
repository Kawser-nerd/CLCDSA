#include<stdio.h>
int srx,sry,lhy,mzy,zjq,lgx[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char t;
int main()
{
   scanf("%d%c%d%c%d",&srx,&t,&sry,&t,&lhy);
   if(srx%4==0&&srx%100!=0&&srx%400!=0||srx%400==0&&srx%4==0)
   lgx[2]=29;
   for(mzy=sry;mzy<=12;mzy++)
   {for(zjq=lhy;zjq<=lgx[mzy];zjq++)
   if(srx%mzy==0&&(srx/mzy)%zjq==0)
   {if(mzy>9&&zjq>9)
   {printf("%d/%d/%d\n",srx,mzy,zjq);
   return 0;}
   else if(mzy<10&&zjq<10)
   {printf("%d/0%d/0%d\n",srx,mzy,zjq);
   return 0;}
   else if(zjq<10)
   {printf("%d/%d/0%d\n",srx,mzy,zjq);
   return 0;}
   else if(mzy<10)
   {printf("%d/0%d/%d\n",srx,mzy,zjq);
   return 0;}}
   lhy=1;}
   printf("%d/01/01\n",srx+1);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%c%d%c%d",&srx,&t,&sry,&t,&lhy);
    ^