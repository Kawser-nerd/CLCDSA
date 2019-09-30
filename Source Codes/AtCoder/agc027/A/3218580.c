#include <stdio.h>
#include <string.h>
int main()
{
	int N;
	long long int x;
	scanf("%d%lld",&N,&x);
	long long int a[N];
	int i,j,tmp;
	for(i = 0; i<N;i++){
		scanf("%lld",&a[i]);
	}
	for(i = 0; i<N;i++){
		for(j=N-1;j>i;j--){
			if(a[j]<a[j-1]){
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
	}
	int count=0;
	for(i = 0;i<N;i++){
		if(i!=N-1){
			if(x>=a[i]){
				x-=a[i];
				count++;
			}
			else break;
		}
		else{
			if(x==a[i]){
				count++;
			}else break;
		}
	}

	printf("%d",count);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&N,&x);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^