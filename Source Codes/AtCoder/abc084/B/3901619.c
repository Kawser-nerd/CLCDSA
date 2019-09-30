#include<stdio.h>
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	long long int n, s[5000] = {},m,min=10000000,count=0,x;
	char str[3000];
	scanf("%lld%lld", &n,&m);
	scanf("%s",str);
	
	for (int i = 0; i < n; i++) {
		if (str[i]-'0'<0|| str[i] - '0' > 9) { printf("No"); return 0; }
	}
	if (str[n]!='-') { printf("No"); return 0; }
	for (int i = n+1; i < n+m+1; i++) {
		if (str[i] - '0' < 0 || str[i] - '0' > 9) { printf("No"); return 0; }
	}
	printf("Yes");
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &n,&m);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^