#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long m[1000];
int B;

long long howmany(long long tme) {
    long long npeople = 0;
    for (int i = 0; i < B; i++)
        npeople += 1 + tme/m[i];
    return npeople;
}

int main() {
    int T;
    cin >> T;

    for (int z = 1; z <= T; z++) {
        int N;
        cin >> B >> N;

        for (int i = 0; i < B; i++)
            cin >> m[i];

        long long lo = 0, hi = 1000000000000000LL;
        while (lo < hi) {
            long long mid = (lo+hi)/2;

            if (howmany(mid) >= N)
                hi = mid;
            else
                lo = mid+1;
        }
        assert(hi < 1000000000000000LL);

        long long prev = lo == 0 ? 0 : howmany(lo - 1);
        assert(prev < N);

        int ans = -1;
        for (int i = 0; i < B; i++) {
            if (lo % m[i] == 0)
                prev++;
            if (prev == N) {
                ans = i;
                break;
            }
        }

        assert(ans != -1);
        cout << "Case #" << z << ": " << ans+1 << endl;
    }
}
