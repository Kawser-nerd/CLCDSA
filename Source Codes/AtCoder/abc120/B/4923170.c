#include<stdio.h>

int main(void)
{
   int a,b,k,tmp,x,i,f[100];
   scanf("%d %d %d",&a,&b,&k);
   if (1>a) return 1;
   else if (b>100) return 1;
   else if (k<1) return 1;

   if(a<b){
        tmp=a;
        a=b;
        b=tmp;
   }
   for(i=1;i<=b;i++){
        if(a%i==0&&b%i==0){
           x++;
           f[x]=i;
        }
   }

   printf("%d\n",f[x-k+1]);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d %d",&a,&b,&k);
    ^