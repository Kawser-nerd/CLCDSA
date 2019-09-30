#include<stdio.h>

int main(){
int l,r,n,i,a;
scanf("%d%d%d",&l,&r,&n);
for(i=0;i<n;i++){
scanf("%d",&a);
if(a<l)printf("%d\n",l-a);
else if(a<=r)puts("0");
else puts("-1");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d",&l,&r,&n);
 ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^