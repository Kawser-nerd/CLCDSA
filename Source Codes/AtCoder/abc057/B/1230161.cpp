#include<stdio.h>
#include <math.h>
#include <stdlib.h>
int main (){
	//kkc
int n,m,a[52],b[52],c[52],d[52],i,j,e,f,g;
scanf("%d %d",&n, &m);
for(i=1;i<=n;i++){
scanf("%d %d",&a[i],&b[i]);
}
for(i=1;i<=m;i++){
scanf("%d %d",&c[i],&d[i]);
}
for(i=1;i<=n;i++){
e=500000000;
for(j=m;j>=1;j--){
f=abs(a[i]-c[j])+abs(b[i]-d[j]);
if (f<=e) {
e=f;
g=j;
}
}
printf("%d\n",g);
}
return 0;
}