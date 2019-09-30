#include<stdio.h>
int main()
{
	int a[100005];
	int n;
	scanf("%d",&n);
	long long sum=0;
	int b[100005]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(int i=0;i<n;i++){
		int t=a[i];
		a[i]++;
		b[a[i]]++;
		t--;
		b[t]++;
	}
	int max=0;
	for(int i=0;i<100005;i++){
		if(max<b[i])
			max=b[i];	
	}
	printf("%d\n",max);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^