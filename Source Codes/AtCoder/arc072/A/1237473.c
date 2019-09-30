#include <stdio.h>
#include <stdlib.h>

long long int min(long long int a, long long int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int n, i;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	long long int ans1 = 0, ans2 = 0, sum = 0;
	int f = -1;
	for(i = 0; i < n; i++){
		sum += a[i];
		if(f == 1 && sum <= 0){
			ans1 += 1 - sum;
			sum = 1;
		}
		else if(f == -1 && sum >= 0){
			ans1 += 1 + sum;
			sum = -1;
		}
		if(f == 1){
			f = -1;
		}
		else if(f == -1){
			f = 1;
		}
	}
	f = 1;
	sum = 0;
	for(i = 0; i < n; i++){
		sum += a[i];
		if(f == 1 && sum <= 0){
			ans2 += 1 - sum;
			sum = 1;
		}
		else if(f == -1 && sum >= 0){
			ans2 += 1 + sum;
			sum = -1;
		}
		if(f == 1){
			f = -1;
		}
		else if(f == -1){
			f = 1;
		}
	}
	printf("%lld\n", min(ans1, ans2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^