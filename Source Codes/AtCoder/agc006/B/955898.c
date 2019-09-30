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
	/* === input paramater === */
	int n,x;

	/* === paramater === */
	int i;
	int counter;
	/* === input === */
	scanf("%d%d",&n,&x);
	if(x == 1 || x == 2*n-1){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if(n==2){
		printf("%d\n%d\n%d\n",1,2,3);
		return 0;
	}
	counter = 1;
	if(x==2){
		for(i=0;i<n-2;i++){
			if(counter == x-1){
				counter += 4;
			}
			printf("%d\n", counter);
			counter++;
			if(counter == x-1){
				counter += 4;
			}
		}
		printf("%d\n%d\n%d\n%d\n",x+1,x,x-1,x+2);
		for(i=0;i<n-3;i++){
			if(counter == x-1){
				counter+=4;
			}
			printf("%d\n", counter);
			counter++;
			if(counter == x-1){
				counter+=4;
			}
		}
		return 0;
	}
	for(i=0;i<n-3;i++){
		if(counter == x-2){
			counter += 4;
		}
		printf("%d\n", counter);
		counter++;
		if(counter == x-2){
			counter += 4;
		}
	}
	printf("%d\n%d\n%d\n%d\n",x-2,x+1,x,x-1);
	for(i=0;i<n-2;i++){
		if(counter == x-2){
			counter += 4;
		}
		printf("%d\n", counter);
		counter++;
		if(counter == x-2){
			counter+=4;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&x);
  ^