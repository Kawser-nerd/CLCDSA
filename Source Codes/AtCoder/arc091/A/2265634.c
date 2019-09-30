#include<stdio.h>
int main()
{
   int n,m,i,j,jp;
   long long int area;
   scanf("%d %d",&n,&m);
   if(n==1||m==1)
   {
   if(n==1&&m==1) printf("1");
   else printf("%d",n+m-3);
   }
   else
   {
   area=n-2;
   area=area*(m-2);
   printf("%lld",area);
   }
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&n,&m);
    ^