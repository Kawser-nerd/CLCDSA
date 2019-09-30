#include <stdio.h>
#include <string.h>
void solve(void)
{
   int y;
   int m;
   int d,dmax[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   scanf("%d/%d/%d",&y,&m,&d);
   if(y%400==0 || y%100!=0 && y%4==0 ){
       ++dmax[2];
   }
   if(y%m==0){
       for(; d<=dmax[m]; ++d){
           if((y/m)%d==0){
               break;
           }
       }
   } else {
     d=32;
   }
   
   if(d>dmax[m]){
       d=1;
       for(++m; m<13; ++m){
           if(y%m==0){
               break;
           }
       }
   }
   if(m>=13){
       m=1;
       ++y;
   }
   printf("%04d/%02d/%02d\n",y,m,d);
}
int main(int argc, char **argv)
{
   solve();
   return 0;
} ./Main.c: In function ‘solve’:
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d/%d/%d",&y,&m,&d);
    ^