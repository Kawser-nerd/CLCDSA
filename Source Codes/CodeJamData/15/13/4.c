#include<stdio.h>
int t,T;
long long X[3001];
long long Y[3001];
int n,N;
int n1,n2,n3;
int ans1, ans2;
int ANS[3001];
long long tmp;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);
for(n=0;n<N;n++){
 scanf("%lld",&X[n]);
 scanf("%lld",&Y[n]);
 ANS[n]=N;
 } 

if (N<=2) ANS[0]=ANS[1]=0;

for(n1=0;n1<N;n1++)
for(n2=n1+1;n2<N;n2++)
{
ans1=0;
ans2=0;
for(n3=0;n3<N;n3++){
 if ((n3==n1)||(n3==n2)) continue;
 tmp=(X[n2]-X[n1])*(Y[n3]-Y[n2])-(X[n3]-X[n2])*(Y[n2]-Y[n1]);
 if (tmp<0) ans1++;
 else if (tmp>0) ans2++;
}
if (ans2<ans1) ans1=ans2;
if (ANS[n1]>ans1) ANS[n1]=ans1;
if (ANS[n2]>ans1) ANS[n2]=ans1;
}

 printf("Case #%d:\n",t);
for(n=0;n<N;n++) printf("%d\n",ANS[n]);
}
return 0;
}
