#include<stdio.h>
int main(void){
	int n,i,j,z = 0;
	long int a[100],x,s;
	scanf("%d",&n);
	scanf("%ld",&x);
	for(i = 0;i < n;i++){
	scanf("%ld",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
		if(a[i] > a[j]){
			s = a[i];
			a[i] = a[j];
			a[j] = s;
		}
		}
	}
	for(i=0;i<n;i++){
		if(x - a[i] >= 0){
			x -= a[i];
			z++;
			if(z == n && x > 0)z--;
		}
		else break;
	}
	printf("%d\n",z);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&x);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&a[i]);
  ^