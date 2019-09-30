#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 250
int main()
{
   int cases,cnt;
   int i,n,sum,j,k;
   int a[MAX];
   for(scanf("%d",&cases),cnt=1;cnt<=cases;cnt++){
      printf("Case #%d:",cnt);
      scanf("%d",&n);
      sum=0;
      for(i=0;i<n;i++){
         scanf("%d",&a[i]);
         sum+=a[i];
      }
      for(i=0;i<n;i++){
         long double h=100.0,l=0.0,m,score;
         for(k=0;k<200;k++){
            m=(h+l)/2;
            score=a[i]+sum*m/100;
            //printf("\tscore will be %Lf for candidate %d when he gets %Lf votes\n",score,i,m);
            long double total=1-m/100,diff;
            for(j=0;j<n;j++)
               if(j!=i){
                  diff=(score-a[j])/sum;
                  if(diff>0) total-=diff;
                  if(total<0) break;//he will qualify
               }
            if(total<0) h=m;
            else l=m;
         }
         printf(" %Lf",m); 
      }
      printf("\n");
   }
   return 0;
}
