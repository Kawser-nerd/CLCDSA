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
	long long int n, m, k,p,q;
	char str[30],str2[15],str3[15];
	scanf("%s",str);
	
	
	
		printf("%s",str);
	 printf("s\n");
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^