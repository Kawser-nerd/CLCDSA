#include<stdio.h>
int t,T,X;
int foo[1024];
int n,N;
int ans1,ans2;
int rate;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);
for(n=0;n<N;n++){
 scanf("%d",&foo[n]);
 } 
ans1=0;
ans2=0;
rate=0;
for(n=1;n<N;n++){
if (foo[n]<foo[n-1]) ans1+=foo[n-1]-foo[n];
if (foo[n-1]-foo[n]>rate) rate=foo[n-1]-foo[n];
}

for(n=1;n<N;n++){
if (foo[n-1]<rate) ans2+=foo[n-1];
else ans2+=rate;
}


 printf("Case #%d: %d %d\n",t,ans1,ans2);
}
return 0;
}
