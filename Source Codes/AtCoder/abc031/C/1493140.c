#include <stdio.h>
#include <limits.h>

static int score(int takahashi, int a[50], int N);

/* ????????? */
int main(int argc, char *argv[])
{
	int i, N, a[50], max = INT_MIN, c;
	scanf("%d", &N);
	for ( i = 0; i < N; i++ ){
		scanf("%d", &a[i]);
	}
	for ( i = 0; i < N; i++ ){
		c = score(i, a, N);
		if ( c > max ){
			max = c;
		}
	}
	printf("%d\n", max);
	return 0;
}

static int score(int takahashi, int a[50], int N)
{
	int i, j, n, from, to;
	int as_max = INT_MIN, ts, as, ret = 0;

	for ( i = 0; i < N; i++ ){
		if ( i == takahashi ){
			continue;
		}
		from = takahashi>i?i:takahashi;
		to   = takahashi>i?takahashi:i;
		for ( j = from, n = 1, ts = 0, as = 0; j <= to; j++, n++ ){
			if ( n%2 == 0 ){
				as += a[j];
			} else {
				ts += a[j];
			}
		}
		if ( as > as_max ){
			as_max = as;
			ret = ts;
		}
	}

	return ret;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^