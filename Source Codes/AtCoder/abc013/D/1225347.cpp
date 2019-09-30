#include<stdio.h>
#include<math.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int *x) { int k, m = 0; *x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { *x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; *x = (*x) * 10 + k - '0'; }if (m)(*x) = -(*x); }
void reader(int *x, int *y) { reader(x); reader(y); }
void reader(int *x, int *y, int *z) { reader(x); reader(y); reader(z); }
void writer(int x, char c) { int i, sz = 0, m = 0; char buf[10]; if (x<0)m = 1, x = -x; while (x)buf[sz++] = x % 10, x /= 10; if (!sz)buf[sz++] = 0; if (m)mypc('-'); while (sz--)mypc(buf[sz] + '0'); mypc(c); }

int a[30][100000];
int ans[100000];
int main() {
	int n, m, d; reader(&n, &m, &d);
	rep(i, n)a[0][i] = i;
	int LOG = log2(d) + 1;
	rep(i, m) {
		int b; reader(&b);
		a[0][b - 1] ^= a[0][b] ^= a[0][b - 1] ^= a[0][b];
	}
	for (int i = 1; i < LOG; i++) {
		rep(j, n) {
			a[i][j] = a[i - 1][a[i - 1][j]];
		}
	}
	rep(i, n) {
		int p = i;
		rep(i, LOG) {
			if (d >> i & 1)p = a[i][p];
		}
		ans[p] = i;
	}
	rep(i, n)writer(ans[i] + 1, '\n');
}