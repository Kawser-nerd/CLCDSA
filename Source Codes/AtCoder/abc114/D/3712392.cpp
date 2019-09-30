#include <iostream>
#include <vector>

using namespace std;

int n;

bool primes[101];
int factor[101];

int main(){
    cin >> n;

    for (int i = 0; i < 101; ++i) {
        primes[i] = true;
        factor[i] = 0;
    }

    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < 101; ++i) {
        if (primes[i]) {
            for (int k = i + i; k < 101; k += i) {
                primes[k] = false;
            }
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 2; i <= k; ++i) {
            if (!primes[i]) continue;
            int cnt = 0;
            int t = k;
            while (t % i == 0) {
                t /= i;
                cnt++;
            }
            factor[i] += cnt;
        }
    }
    int ans = 0;
    int ans3 = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; j++) {
            for (int k = 2; k <= n; k++) {
                if (i == j || j == k || i == k) continue;
                if (factor[i] >= 2 && factor[j] >= 4 && factor[k] >= 4) ans3++;
            }
            if (i != j) {
                if (factor[i] >= 14 && factor[j] >= 4) ans++;
                if (factor[i] >= 24 && factor[j] >= 2) ans++;
            }
        }
        if (factor[i] >= 74) ans++;
    }
    cout << ans + ans3 / 2 << endl;
}