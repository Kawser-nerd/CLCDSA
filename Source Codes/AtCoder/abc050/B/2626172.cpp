#include <iostream>
#define REP(a) for(i=0;i<a;i++)

int main(){

   int i, n, m, t0[110], p, t1, t2[101], sum=0;
   scanf("%d",&n);
   REP(n){
     scanf("%d",&t0[i]);
     sum+=t0[i];
   }
   scanf("%d",&m);
   REP(m){
     scanf("%d %d",&p,&t1);
     t2[i]=sum-t0[p-1]+t1;
   }
   REP(m)printf("%d\n",t2[i]);
 }