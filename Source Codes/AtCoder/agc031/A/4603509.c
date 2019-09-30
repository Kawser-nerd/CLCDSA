#include<stdio.h>
#include<stdlib.h>

long long int search(char str[], char sear,int n) {
	int i;
	int num = 0;

	for (i = 0;i < n;i++) {
		if (str[i] == sear) {
			num++;
		}
	}
	return num;
}

int main() {
	int i, j, k, f = 0, n, t, m;
	int a, b, c, d, e;
	int z;
	long long int x, y;
	char s[1100000];
	long long int b0[30];
	char a0[30];
	y = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;

	scanf("%d", &n);
	scanf("%s", s);

	i = 0;
	a0[i] = 'a';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'b';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'c';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'd';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'e';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'f';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'g';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'h';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'i';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'j';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'k';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'l';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'm';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'n';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'o';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'p';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'q';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'r';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 's';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 't';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'u';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'v';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'w';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'x';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'y';
	b0[i] = search(s, a0[i],n) + 1;
	i++;
	a0[i] = 'z';
	b0[i] = search(s, a0[i],n) + 1;


	x = 1;

	for (i = 0;i < 26;i++) {
		x = x * b0[i]%y;
	}


	x = x - 1;
	x = x % y;

	printf("%lld", x);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^