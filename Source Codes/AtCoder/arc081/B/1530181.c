#include <stdio.h>

int main()
{
 int N;
 char s1[54];
 char s2[54];
 int i;
 long long ways=1;
 int start;

 scanf("%d",&N);
 scanf("%s",s1);
 scanf("%s",s2);


 if(s1[0]==s2[0]) 
 {
   ways=3;
   start=1;
 }else{
   ways=6;
   start=2;
 }

 for(i=start;i<N;i++)
 {
   if((s1[i]==s2[i])&(s1[i-1]==s2[i-1])) 
   {
     /*  ab
         ab */
     ways=ways*2;
     ways=ways%1000000007;
   }else if((s1[i]==s2[i])&(s1[i-1]!=s2[i-1]))
   {
     /* aab
        ccb  */
   }else if((s1[i]!=s2[i])&(s1[i-1]==s2[i-1]))
   {
     /* abb
        acc */
     ways=ways*2;
     ways=ways%1000000007;
     i++;
   }else{
    /*  aabb
        ccaa  */
    ways=ways*3;
     ways=ways%1000000007;
     i++;
   }
 }
 printf("%lld \n",ways); 
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s1);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s2);
  ^