#include <stdio.h>
int main (){
int i,a,b,k[101]={0},max=0,sum=0;
scanf ("%d",&a);
for (i=0;i<a;i++){
	scanf ("%d",&k[i]);
	if (max<k[i]){
	max=k[i];
	b=i;
		}
	}
	for (i=0;i<a;i++){
	if (i==b){
	sum=sum+(k[i]/2);
		}
		else
		{	
		sum=sum+k[i];
		}
		}
		printf ("%d",sum);
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&a);
 ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d",&k[i]);
  ^