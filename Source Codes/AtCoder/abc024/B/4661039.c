#include<stdio.h>
int main(){
	int a[1000002],n,k,i,sum=0;
	scanf ("%d%d",&n,&k);
	for (i=0;i<n;i++){
	scanf("%d",&a[i]);
		}
	for (i=0;i<n-1;i++){
		if (a[i+1]-a[i]<k){
			sum=sum+a[i+1]-a[i];
			}
			else
			{
				sum=sum+k;
			}
		}
		printf ("%d\n",sum+k);
return 0;	
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d%d",&n,&k);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a[i]);
  ^