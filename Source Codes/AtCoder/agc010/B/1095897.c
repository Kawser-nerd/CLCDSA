#include<stdio.h>

long a[100001];

int main(int argc, char const *argv[]) {
	long n,i,sum=0,num;
	scanf("%ld",&n);
	for(i=0;i<n;i++){
		scanf("%ld",&a[i]);
		sum+=a[i];
	}
	a[n]=a[0];
	for(i=0;i<n;i++){
		a[i]=a[i+1]-a[i];
	}
	num=n*(n+1)/2;
	if(sum%num==0){
		num=sum/num;
		for(i=0;i<n;i++){
			a[i]-=num;
			a[i]=-a[i];
			if(a[i]<0 || a[i]%n!=0) break;
		}
		if(i==n) printf("YES\n");
		else printf("NO\n");
	}else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a[i]);
   ^