#include<stdio.h>

#define SIZE 20
#define INF 999999999999999999

int Case;
char st1[SIZE], st2[SIZE];
int len1, len2;
long long min1, min2, dif, d, v1, v2;
char num1[SIZE], num2[SIZE];
char out1[SIZE], out2[SIZE];

long abs(long n)
{
	if (n < 0)
		return -n;
	return n;
}

void readCase()
{
	scanf("%s %s", st1, st2);
}

void solve(int x, int y)
{
	int i;
	if (!dif)
		return;
	if (x == len1 && y == len2) {
		v1 = v2 = 0;
		for (i=0; i<len1; i++)
			v1 = v1*10 + num1[i]-'0';
		for (i=0; i<len2; i++)
			v2 = v2*10 + num2[i]-'0';
		d = abs(v1-v2);
		if (d < dif) {
			dif = d;
			min1 = v1;
			min2 = v2;
			for (i=0; i<len1; i++)
				out1[i] = num1[i];
			for (i=0; i<len2; i++)
				out2[i] = num2[i];
		}
		else if (d == dif) {
			if (v1 < min1) {
				min1 = v1;
				min2 = v2;
				for (i=0; i<len1; i++)
					out1[i] = num1[i];
				for (i=0; i<len2; i++)
					out2[i] = num2[i];
			}
			else if (v1 == min1 && v2 < min2) {
				min2 = v2;
				for (i=0; i<len2; i++)
					out2[i] = num2[i];
			}
		}
		return;
	}
	if (x < len1) {
		if (st1[x] == '?') {
			for (i=0; i<10; i++) {
				num1[x] = i+'0';
				solve(x+1, y);
			}
		}
		else {
			num1[x] = st1[x];
			solve(x+1, y);
		}
	}
	else if (y < len2) {
		if (st2[y] == '?') {
			for (i=0; i<10; i++) {
				num2[y] = i+'0';
				solve(x, y+1);
			}
		}
		else {
			num2[y] = st2[y];
			solve(x, y+1);
		}
	}
}

void solveCase()
{
	for (len1=0; st1[len1]; len1++);
	for (len2=0; st2[len2]; len2++);
	out1[len1] = 0;
	out2[len2] = 0;
	min1 = min2 = dif = INF;
	solve(0, 0);
}

void printCase()
{
	printf("Case #%d: %s %s\n", Case, out1, out2);
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case=1; Case<=T; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
