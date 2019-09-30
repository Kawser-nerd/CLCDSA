// AtCoder Regular Contest 080 C - 4-adjacent
// 2018.1.11 bal4u

#include <stdio.h>
#include <string.h>

#define getchar_unlocked()  getchar()
int in()
{
	int n = 0;
	int c = getchar_unlocked();
	do n = (n<<3)+(n<<1) + (c & 0xf), c = getchar_unlocked();
	while (c >= '0');
	return n;
}

int main()
{
	int N, a;
	int i, n4, odd, ans;			// n4: 4???

	odd = n4 = 0;
	N = in();
	for (i = 0; i < N; i++) {
		a = in();
		if (a & 1) odd++;
		else if (!(a & 3)) n4++;
	}
	ans = 0;
	if (n4 >= odd) ans = 1;
	else if (n4 == odd-1 && odd + n4 == N) ans = 1;
	puts(ans? "Yes": "No");
	return 0;
}