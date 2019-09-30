#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _compare(const void *a, const void *b) {
	if(*(char *)a < *(char *)b)
		return -1;
	else if(*(char *)a == *(char *)b)
		return 0;
	else
		return 1;
}

int main(void) {
	char A[200000];
	long int start[26] = {0};
	long int end[26] = {0};
	int sp = 0;
	long long int ans = 0, k, l;
	
	scanf("%s", A);
	ans++;
	ans += strlen(A) * (strlen(A)-1) / 2;
	qsort(A, strlen(A), sizeof(*A), _compare);
	for(k=0; k<strlen(A)-1; k++) {
		if(A[k] != A[k+1]) {
			end[sp] = k;
			start[++sp] = k+1;
		}
	}
	end[sp] = strlen(A)-1;
	for(k = 0; k <= sp; k++) {
		ans -= (end[k] - start[k] + 1) * (end[k] - start[k]) / 2;
	}
	/*
	for(k = 2; k <= strlen(A); k++) {
		ans += strlen(A)-k+1;
		char_count[A[k-1]-97]++;
	}
	*/
	/*
	for(k=0; k < 26; k++) {
		ans -= char_count[k] * (char_count[k]-1) / 2;
	}
	*/
	/*
	for(k = 1, l = 1, m = 0; k < strlen(A) - 1; k++) {
		if(A[k] == A[k+1]) {
			if(k-1 < strlen(A) - 1) {
			ans--;
			for(m = 1; k-m >= 0 && k+1+m <= strlen(A)-1; m++) {
				if(A[k-m] == A[k+1+m])
					ans--;
				else
					break;
			}
			m = 0;
		}
		if(A[k-l] == A[k+l]) {
			ans--;
			for(l = 2; k-l >= 0 && k+l <= strlen(A)-1; l++) {	
				if(A[k-l] == A[k+l])
					ans--;
				else
					break;
			}
			l = 1;
		}
	}
	// ???????
	for(k = 0, l = 0; k < strlen(A) - 1; k++) {
		if(A[k] == A[k+1]) {
			ans--;
			for(l = 1; k-l >= 0 && k+1+l <= strlen(A)-1; l++) {
				if(A[k-l] == A[k+1+l])
					ans--;
				else
					break;
			}
			l = 0;
		}
	}
	*/

	printf("%lld", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", A);
  ^