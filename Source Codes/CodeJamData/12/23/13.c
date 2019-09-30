
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 25
int main()
{
   int cases,cnt;
   int i,n;
   int a[MAX],choice[MAX];
   for(scanf("%d",&cases),cnt=1;cnt<=cases;cnt++){
      printf("Case #%d:\n",cnt);
      scanf("%d",&n);
      long long int cnt=0;
      for(i=0;i<n;i++)
         scanf("%d",&a[i]);
      memset(choice,0,sizeof(choice));
      while(choice[n]==0){
         int s0=0,s1=0;
         for(i=0;i<n;i++)
            if(choice[i]==0) s0+=a[i];
            else if(choice[i]==1) s1+=a[i];
         //         printf("cnt is %lld,s0 is %d s1 is %d\n",cnt,s0,s1);
         cnt++;
         if(s0==s1)
            if(s0>0){
               //printf("s0 is %d and s1 is %d\n",s0,s1);
               break;
            }
         i=-1;
         do{
            i++;
            choice[i]=(choice[i]+1)%3;
         }while(choice[i]==0);
      }
      if(choice[n]!=0) printf("Impossible\n");
      else{
         for(i=0;i<n;i++)
            if(choice[i]==0) printf("%d ",a[i]);
         printf("\n");
         for(i=0;i<n;i++)
            if(choice[i]==1) printf("%d ",a[i]);
         printf("\n");
      }
   }
   return 0;
}
