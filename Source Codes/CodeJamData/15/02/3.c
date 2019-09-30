#include<stdio.h>
int t,T;
int d,D;
int target;
int ans;
int best;
int P[1024];
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&D);

for(d=0;d<D;d++){
scanf("%d",&P[d]);
}

best=0;
for(d=0;d<D;d++) if (P[d]>best) {best=P[d];}

for (target=best-1;target>0;target--) {
ans=target;
for(d=0;d<D;d++) ans+=(P[d]-1)/target;
if (best>ans) best=ans;
}



 printf("Case #%d: %d\n",t,best);
}
return 0;
}
