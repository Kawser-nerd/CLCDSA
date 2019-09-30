#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,n;

   char s[101];
   int sum,max=0,k;
   scanf("%d",&n);
   scanf("%s",s);

   for (i=0;i<n;i++)
   {
  int a[101]={0};
   int b[101]={0};
    for (k=0;k<=i;k++)
    a[s[k]-'a']=1;
    for(j=i+1;j<n;j++)
    b[s[j]-'a']=1;
         sum=0;
       for(j=0;j<26;j++)
        {
            if(a[j]==1&&b[j]==1)
            sum++;
        }
 if(sum>max)
    max=sum;
   }
   printf("%d",max);

return 0;

   } ./Main.c: In function ‘main’:
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&n);
    ^
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",s);
    ^