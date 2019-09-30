#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int64;
#define debug(x) cerr << #x << " = " << (x) << endl;

const int MOD = 1000000007;

int ndigits(int64 x) {
    int n = 0;
    while ( x > 0 ) { ++n; x/=10; }
    return n;
}

int64 reverse(int64 x) {
    int64 y = 0;
    while ( x > 0 ) { y = 10*y+x%10; x/=10; }
    return y;
}

int64 multpow10(int64 x, int p) {
    while ( p-- > 0 ) { x *= 10; }
    return x;
}

int64 pairs(int64 x) {
    x %= MOD;
    return x * (x+1) / 2 % MOD;
}

vector<int64> preprocess(int64 L, int64 R) {
    vector<int64> pals;
    for ( int64 seed=1;; ++seed ) {
        int n = ndigits(seed);
        // fprintf(stderr, "seed = %d, n = %d\n", int(seed), n);
        int64 x = multpow10(seed/10, n) + reverse(seed);
        if ( x > R ) break;
        if ( x >= L && x <= R ) pals.push_back(x);

        x = multpow10(seed, n) + reverse(seed);
        if ( x >= L && x <= R ) pals.push_back(x);
    }
        
    // cerr << pals << endl;
    sort(pals.begin(), pals.end());
    return pals;
}

int main(void) { 
    cin.sync_with_stdio(0);

    vector<int64> allpals = preprocess(1, 10000000000000LL);

    int CASES; cin >> CASES;
    for ( int tt=1; tt<=CASES; ++tt ) { // caret here
        int64 L, R; cin >> L >> R;

        vector<int64> pals(lower_bound(allpals.begin(), allpals.end(), L),
                           upper_bound(allpals.begin(), allpals.end(), R));
        int N = pals.size();

        int64 ans = 0;
        if ( N > 0 ) {
            vector<int64> weights(N);
            for ( int i=0; i<N-1; ++i ) weights[i] = (pals[i+1] - pals[i]) % MOD;
            weights[N-1] = R-pals[N-1]+1;
            // cerr << weights << endl;
            
            int64 oddsum = 0, evensum = 0;
            for ( int i=0; i<N; i+=2 ) evensum += weights[i];
            for ( int i=1; i<N; i+=2 ) oddsum += weights[i];
            evensum %= MOD; oddsum %= MOD;
            
            // debug(evensum);
            // debug(oddsum);
            
            for ( int i=0; i<N; ++i ) {
                int64 &sum = i%2 == 0 ? evensum : oddsum;
                sum = (sum + MOD - weights[i]) % MOD;
                
                int64 sum2 = i%2 != 0 ? evensum : oddsum;
                int64 before = (i == 0 ? pals[0]-L+1 : pals[i] - pals[i-1]) % MOD;
                ans += before * sum2 % MOD;
                ans %= MOD;
                // fprintf(stderr, "i = %d, before = %d, sum2 = %d\n", i, int(before), int(sum2));
            }

            ans += pairs(pals[0] - L); ans %= MOD;
            for ( int i=0; i<N; ++i ) { ans += pairs(weights[i] - 1); ans %= MOD; }
        } else {
            ans = pairs(R-L+1);
        }
        cout << "Case #" << tt << ": " << ans%MOD << "\n";
    }

    return 0;
} 
