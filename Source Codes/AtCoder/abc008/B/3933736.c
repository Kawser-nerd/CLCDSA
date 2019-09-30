#include<stdio.h>
#include<string.h>
int n,i,j,sry,lhy,lgx[51],lyj;
char srx[51][51],t[51];
int main()
{
   scanf("%d",&n);
   for(i=1;i<=n;++i)
   {scanf("%s",t);
   if(sry==0)
   {sry++;
   strcpy(srx[sry],t);
   continue;}
   for(j=1;j<=sry;++j)
   if(strcmp(srx[j],t)==0)
   {lgx[j]++;
   lhy=1;
   break;}
   if(lhy==0)
   {sry++;
   strcpy(srx[sry],t);}
   lhy=0;}
   for(i=1;i<=sry;++i)
   if(lyj<lgx[i])
   {lyj=lgx[i];
   strcpy(t,srx[i]);}
   puts(t);
   return 0;
   } ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&n);
    ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    {scanf("%s",t);
     ^