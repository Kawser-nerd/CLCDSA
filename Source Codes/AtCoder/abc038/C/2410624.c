#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int a[100001], start[100001];
long int sum=0;

void change(int *x, int *y){
	int z;
	z = *x;
	*x = *y;
	*y = z;
}
int compare_int(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	scanf("%d", &n );
	for(int i=0;i<n;i++)	scanf("%d", &a[i]);

	if(n==1)	printf("1");
	else{
		start[0] = 0;
		for(int i=1;i<n;i++){
			if(a[i] > a[i-1])	start[i] = start[i-1];
			else	start[i] = i;
		}
			
		for(int i=0;i<n;i++){
			sum += i - start[i] + 1;
		}
		printf("%lld", sum);
	}
				
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:10: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘long int’ [-Wformat=]
   printf("%lld", sum);
          ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n );
  ^
./Main.c:21:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
                       ^