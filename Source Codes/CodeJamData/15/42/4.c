#include<stdio.h>
int n,t,T,N;
int r,c;
long double ans;
long double R[128];
long double C[128];
long double V,X;
long double min;
long double C_tmp,R_tmp;
int imp1, imp2;
long double ans1, ans2,ans;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);
scanf("%llf",&V);
scanf("%llf",&X);
imp1=1; imp2=1;
for(n=0;n<N;n++){
scanf("%llf",&R[n]);
scanf("%llf",&C[n]);
if (C[n] <= X) imp1=0;
if (C[n] >= X) imp2=0;
}
if ((imp1==1)||(imp2==1)) {printf("Case #%d: IMPOSSIBLE\n",t); continue;}

if (N==1) ans=V/R[0];
else if (N==2) {
if (C[0]==C[1]) {ans=V/(R[0]+R[1]);}
else{
 if (C[1]<C[0]) {
  C_tmp=C[0];C[0]=C[1];C[1]=C_tmp;
  R_tmp=R[0];R[0]=R[1];R[1]=R_tmp;
 }
min=C[0];
C[0]-=min;
C[1]-=min;
X-=min;
/*V_1=X*V/(C[1]*R[1]);*/
ans1=X*V/(C[1]*R[1]);
ans2=(V-X*V/C[1])/R[0];
if (ans1>ans2) ans=ans1;
else ans=ans2;
}}

printf("Case #%d: %.9llf\n",t,ans);
}
return 0;
}
