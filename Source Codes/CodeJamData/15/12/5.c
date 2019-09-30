#include<stdio.h>
long long seech();
long long score(long long tim);
int t,T;
long long foo[1024];
long long N;
int b,B;
long long tmp;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&B);
scanf("%lld",&N);
for(b=0;b<B;b++){
 scanf("%lld",&foo[b]);
 } 

tmp=seech();
N-=score(tmp);

for(b=0;b<B;b++){
 if (tmp%foo[b]==0) N--;
 if (N==0) break;
 } 

 printf("Case #%d: %d\n",t,b+1);
}
return 0;
}

long long score(long long tim){
int c=0;
long long anstmp=0;
if (tim==0) return 0;
for(c=0;c<B;c++) {
anstmp+=(tim-1)/foo[c]+1;
}
return anstmp;
}

long long seech(){
long long mintime,maxtime,midtime;
if (score(1)>=N) return 0;
mintime=0;
maxtime=foo[0]*N+2LL;

while(maxtime>=mintime){
midtime=(mintime+maxtime)/2LL;
if (mintime>maxtime) return mintime;
if ((score(midtime)<N)) mintime=midtime;
else maxtime=midtime;

if ((score(mintime)<N)&&(score(mintime+1)>=N)) return mintime;
else mintime++;

if (score(maxtime)<N) return maxtime;
else maxtime--;
}
return -1000000;
}
