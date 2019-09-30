#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define M 1000000007

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int binary_upper(int *a,int n,int k){
    int left = -1;
    int right = n;
	while(right - left>1){
		int mid = (left + right) / 2;
		if(a[mid] <= k) left = mid;
		else right = mid;
	}
	return left;
}

void solve(void){
    int n;
    scanf("%d\n", &n);
    int ds[n];
    rep(n, i) scanf("%d\n", &ds[i]);
    qsort(ds, n, sizeof(int), compare_int);

    long dp[n][4]; //????(????????????)???
    rep(n, i) dp[i][0] = i+1;
    rep(3, i) dp[0][i+1] = 0;
    for (int i = 1; i < n; i++) {
        int index = binary_upper(ds, n, ds[i]/2);
        for (int j = 1; j < 4; j++) {
            dp[i][j] = dp[i-1][j];
            if (index >= 0) dp[i][j] += dp[index][j-1];
            dp[i][j] %= M;
        }
    }

  printf("%ld\n", dp[n-1][3]);
  /*
  rep(n, i) printf("%ld ", g1[i]); printf("\n");
  rep(n, i) printf("%ld ", g2[i]); printf("\n");
  rep(n, i) printf("%ld ", g3[i]); printf("\n");
  rep(n, i) printf("%ld ", g4[i]); printf("\n");
  */

}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:30:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     rep(n, i) scanf("%d\n", &ds[i]);
               ^