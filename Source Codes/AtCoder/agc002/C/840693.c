#include<stdio.h>
 
int main(){
	int n, l, i, max = 0, nmax, sum;
	int a[100005];
	scanf("%d%d", &n, &l);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for(i = 0; i < n - 1; i++){
		sum = a[i] + a[i+1];
		if(max < sum ){
			max = sum;
			nmax = i;
		}
	}
	if(max < l){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	
	for(i = 0; i < nmax; i++)    printf("%d\n", i + 1);
	for(i = n-2; i >= nmax; i--) printf("%d\n", i + 1);
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &l);
  ^
./Main.c:7:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
                         ^