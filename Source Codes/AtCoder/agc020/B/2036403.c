#include<stdio.h>

int main(){
	long k,i,j;
	scanf("%ld",&k);
	
	long long int a[k],b[k],c[k];
	long long int max,min;
	int flag;
	
	for(i=0;i<k;i++){
		scanf("%lld",&a[i]);
	}
	
	if(a[k-1]!=2){
		printf("-1\n");
		return 0;
	}
	
	b[k-1]=1;
	c[k-1]=1;
	
	for(i=k-2;i>=0;i--){
		flag=0;
		max = a[i+1]*(c[i+1]+1)-1; 
		min = a[i+1]*b[i+1];
		if(min - (min%a[i]) + a[i] <= max || min%a[i] == 0){
			flag=1;
		}
		if(flag==0){
			printf("-1");
			return 0;
		}
		b[i]=(a[i+1]*b[i+1])/a[i];
		if((a[i+1]*b[i+1])%a[i]>0){
			b[i]++;
		}
		c[i]=(a[i+1]*(c[i+1]+1)-1)/a[i];
	}
	printf("%lld %lld\n",a[0]*b[0],a[0]*(c[0]+1)-1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&k);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^