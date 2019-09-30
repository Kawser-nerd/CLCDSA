#include<stdio.h>
int t,T;
int S;
int c;
char foo[1024];
int total,current;
int ans;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&S);
scanf("%s",foo);

ans=0;
total=0;
for(c=0;c<=S;c++){
current=foo[c]-48;
if (total<c) {
ans++;
total++;
}
total+=current;
}



 printf("Case #%d: %d\n",t,ans);
}
return 0;
}
