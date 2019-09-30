#include <stdio.h>
int main(){
int n,l[100],i;
scanf("%d",&n);
int sum,max;
sum=0;
max=0;

for(i=0; i<n; i++){
scanf("%d",&l[i]);
sum+=l[i];
if(l[i]>max) max=l[i];

}

if(max>=sum-max) puts("No");
else if(max<sum-max) puts("Yes"); 

return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&n);
 ^
./Main.c:10:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&l[i]);
 ^