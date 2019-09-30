#include <stdio.h>
#include <stdlib.h>
#define N 1010
#define INF 2147483647
int cmp(const void *a, const void *b) {
	if(*(unsigned int *)a > *(unsigned int *)b) return 1;
	else if(*(unsigned int *)a < *(unsigned int *)b) return -1;
	else return 0;
}
unsigned int gcd(unsigned int a, unsigned int b) {
	if(a < b) {
		int temp=a;
		a=b;
		b=temp;
	}
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	int t, T;
	int n;
	unsigned int i, j, k;
	unsigned int num[N];
	unsigned temp;
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d", &n);
		for(i=0;i<n;i++) {
			scanf("%ld", &num[i]);
		}
		qsort(num, n, sizeof(num[0]), cmp);
		if(n > 2) {
			temp = gcd(num[1]-num[0], num[2]-num[1]);
			for(i=3;i<n;i++) {
				temp = gcd(temp, num[i]-num[i-1]);
			}
		}
		else temp = num[1] - num[0];
		if(num[1]%temp == 0)
			printf("Case #%d: 0\n", t+1);
		else
			printf("Case #%d: %ld\n", t+1, temp - (num[1]%temp));
		
	}
	return 0;
}
