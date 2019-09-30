#include <stdio.h>

int lis(int n, int *a, int *b){ //??????????????
	int i;
	int max = 1;
	for(i = 0; i< n; i++){
		b[i] = 1;
		int j;
		for(j = 0; j < i; j++){
			if(a[j] < a[i] && b[j] >= b[i]){//?????????????????????
				b[i] = b[j] + 1;
			}
		}
	}
	int k;
	for(k = 0; k < n; k++){
		if(b[k] > max){
			max = b[k];
		}
	}
	return max;
}

int main(void){
	int max;
	int n;
	scanf("%d",&n);
	
	int c[n];
	int a[n]; //lis????
	int i;
	for(i = 0; i < n; i++){
		scanf("%d",&c[i]);
	}
	
	int j;
	for(j = 0;j < n ; j++){
		a[j] = 1;
	} //??????1???
	
	max = lis(n, c, a); //??????????
	
	printf("%d\n",(n - max));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c[i]);
   ^