#include<stdio.h>
int t,T,X;
int c;
int foo[1024];
int tmp;
int min,max,N;
int ans;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);
scanf("%d",&X);
for(c=0;c<=X;c++){ foo[c]=0;}
for(c=0;c<N;c++){
 scanf("%d",&tmp);
 foo[tmp]++;
 } 
min=1;
max=X;
ans=0;
for(;max>=min;){
 if (foo[max]<=0) {max--; continue;}
 if (foo[min]<=0) {min++; continue;}
 ans++;
 foo[max]--;
 if (min+max <= X) {
 foo[min]--;
 }
}

 printf("Case #%d: %d\n",t,ans);
}
return 0;
}
