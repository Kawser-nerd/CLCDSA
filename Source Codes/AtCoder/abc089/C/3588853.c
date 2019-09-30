#include<stdio.h>

int main(){
int  n,i;
long M=0,A=0,R=0,C=0,H=0;
long long ans=0;
char na[100000][11];
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%s",na[i]);
for(i=0;i<n;i++){
switch(na[i][0]){
case 'M':M++;break;
case 'A':A++;break;
case 'R':R++;break;
case 'C':C++;break;
case 'H':H++;break;
}
}
ans=M*A*R+M*A*C+M*A*H+M*R*C+M*R*H+M*C*H+A*R*C+A*R*H+A*C*H+R*C*H;
printf("%lld\n",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&n);
 ^
./Main.c:9:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 for(i=0;i<n;i++)scanf("%s",na[i]);
                 ^