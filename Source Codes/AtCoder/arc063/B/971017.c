#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))



int main(void){
	int n;
	int t;
	int *a;
	int count;

	int maxval = 0;
	int maxrev = 0;

	int i;

	scanf("%d%d",&n,&t);

	a = calloc(sizeof(int),n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=n-1;i>=0;i--){
		if(a[i] > maxval){
			maxval = a[i];
		}else{
			if(maxval - a[i] == maxrev){
				count++;
			}else if(maxval - a[i] > maxrev){
				count = 1;
				maxrev = maxval - a[i];
			}
		}
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&t);
  ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^