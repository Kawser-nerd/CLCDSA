#include <stdio.h>
#include <stdlib.h>

long long int changeCount(long long int*, int, int);

int main(void){
	/*
	???n???
	*/
	int n;
	if(scanf("%d\n", &n) < 1){
		exit(1);
	}

	/*
	a_1,a_2, ... a_n???
	*/
	long long int *a;
	a = (long long  int*) malloc ( n * sizeof(long long int));
	int i;
	for(i=0; i<n-1; i++){
		if(scanf("%lld ", &a[i]) < 1){ //scanf???????????????????-1???
			//printf(stderr, "error: ill-formed fraction.\n");
			exit(1);
		}
	}
	if(scanf("%lld", &a[n-1]) < 1){
		//printf(stderr, "error: ill-formed fraction.\n");
		exit(1);
	}

	long long int evenchangeCount = changeCount(a, n, 0); //?????????????
	long long int oddchangeCount = changeCount(a, n, 1); //?????????????
	
	if(evenchangeCount <= oddchangeCount){
		printf("%lld", evenchangeCount);
	}else{
		printf("%lld", oddchangeCount);
	}	
	return 0;
}



long long int changeCount(long long int *a, int n, int oddPositive){
	/*
	temp_1?a[0]?a[i-1]????
	temp_2?a[0]?a[i]????
	*/
	long long int temp_1=0;
	long long int temp_2=0;
	long long int changeCount = 0; //?????????????

	int i;
	for(i=0; i < n; i++){
		temp_2 = temp_1 + a[i];

		if(i%2 == 1){ /*i?????*/
			if(oddPositive == 1){//???????????????
				if(temp_2 <= 0){//??????
					changeCount += -temp_2 + 1;
					temp_2 = 1;
				}
			}else{//???????????????
				if(temp_2 >= 0){//??????
					changeCount += temp_2 + 1;
					temp_2 = -1;
				}
			}

		}else{/*i?????*/
			if(oddPositive == 0){//???????????????
				if(temp_2 <= 0){//??????
					changeCount += -temp_2 + 1;
					temp_2 = 1;
				}
			}else{//????????????
				if(temp_2 >= 0){//??????
					changeCount += temp_2 + 1;
					temp_2 = -1;
				}
			}
		}
		temp_1 = temp_2;
	}
	return changeCount;
}