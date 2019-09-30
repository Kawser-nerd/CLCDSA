#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <iostream>


using namespace std;

typedef long long ll;
#define maxn 110
int a_type[maxn], b_type[maxn];
ll a_cnt[maxn], b_cnt[maxn], dp[maxn][maxn];

void relax (ll &x, ll val) {
	if (x < val) {
		x = val;
	}
}

int main (void) {
	int tests_n;
	scanf ("%d", &tests_n);
	for (int test_id = 1; test_id <= tests_n; test_id++) {
		printf ("Case #%d: ", test_id);

    memset (dp, 0, sizeof (dp));
    int an, bn;
    cin >> an >> bn;
    for (int i = 0; i < an; i++) {
      cin >> a_cnt[i] >> a_type[i];
    }
    for (int i = 0; i < bn; i++) {
      cin >> b_cnt[i] >> b_type[i];
    }

    for (int ai = 0; ai <= an; ai++) {
    	for (int bi = 0; bi <= bn; bi++) {
    		ll &res = dp[ai][bi];
    		if (ai > 0) {
    			relax (res, dp[ai - 1][bi]);
    		}
    		if (bi > 0) {
    			relax (res, dp[ai][bi - 1]);
    		}
    		if (ai > 0 && bi > 0) {
    			int a_it = ai - 1, b_it = bi - 1;
    			int tp = a_type[a_it];
    			//fprintf (stderr, "!%d %d\n", tp, b_type[b_it]);
    			if (tp == b_type[b_it]) {
      			ll a_sum = a_cnt[a_it], b_sum = b_cnt[b_it]; 
      			//fprintf (stderr, "?%Ld %Ld\n", a_sum, b_sum);
            relax (res, min (a_sum, b_sum) + dp[a_it][b_it]);
            while (a_it > 0 || b_it > 0) {
            	if (b_it == 0 || (a_it > 0 && a_sum < b_sum)) {
            		a_it--;
            		if (a_type[a_it] == tp) {
            			a_sum += a_cnt[a_it];
            		}
            	} else {
            		b_it--;
            		if (b_type[b_it] == tp) {
            			b_sum += b_cnt[b_it];
            		}
            	}
              relax (res, min (a_sum, b_sum) + dp[a_it][b_it]);
            }
    			} 
    		}
    		//fprintf (stderr, "[%d][%d] = %Ld\n", ai, bi, res);
    	}
    }
    cout << dp[an][bn] << endl;
	}

  

	return 0;
}