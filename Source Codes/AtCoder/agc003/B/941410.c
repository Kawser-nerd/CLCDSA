#include <stdio.h>

int main(){
	int n, num, i;
	long long count=0, sum=0;

	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%d", &num);
		if(num)
			sum+=num;
		else{
			count+=sum/2;
			sum=0;
		}
	}

	if(num)
    count+=sum/2;

	printf("%lld\n", count);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num);
   ^