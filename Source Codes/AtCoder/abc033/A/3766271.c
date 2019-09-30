#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//???
long long int change_plus(long long int a) {
	if (a < 0) { return -a; }
	if (a >= 0) { return a; }
}
//????(?)
long long int big(long long int a, long long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

//????(?)
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int main() {
	char n, m, k,p,q;
	char str[30],str2[15],str3[15];
	scanf("%c%c%c%c",&n,&m,&k,&p);
	
	
	if (n==m&&m==k&&k==p) { printf("SAME\n"); }
	else {
		printf("DIFFERENT\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c%c%c%c",&n,&m,&k,&p);
  ^