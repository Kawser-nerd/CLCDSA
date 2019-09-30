#include<stdio.h>

int main(){
char x[55];
scanf("%s",x);
int i,n=0,f=0;
while(x[n]!=0)n++;
for(i=0;i<n;i++){
if((x[i]=='o')||(x[i]=='k')||(x[i]=='u')||(x[i]=='c'&&x[i+1]=='h'));
else if(i!=0&&(x[i]=='h')&&(x[i-1]=='c'));
else f=1;
}
if(f==1)puts("NO");
else puts("YES");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",x);
 ^