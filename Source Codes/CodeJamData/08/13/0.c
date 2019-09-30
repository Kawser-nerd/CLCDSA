#include <stdio.h>

int mod(int x, int m) { x %= m; if (x < 0) x += m; return x; }

int v[1000][1000], w[1000001];

int main()
{
    int t;

    /*
      (3 + r5)^n = a + b r5
      (3 - r5)^n = a - b r5
      (3 + r5)^n + (3 - r5)^n = 2a
      (3 + r5)^(n+1) = (3a + 5b) + (3b + a)r5
    */

    int a = 1, b = 0, c = 0;
    do {
	v[a][b] = c;
	w[c++] = mod(2*a - 1, 1000);
	int aa = mod(3*a + 5*b, 1000), bb = mod(a + 3*b, 1000);
	a = aa; b = bb;
    } while (!v[a][b]);
    int d = v[a][b];

    scanf("%d\n", &t);
    for (int x = 1; x <= t; ++x)
    {
	int n;
	scanf("%d\n", &n);
	int o = (n < d ? w[n] : w[d + mod(n - d, c - d)]);
	printf("Case #%d: %03d\n", x, o);
    }
    return 0;
}
