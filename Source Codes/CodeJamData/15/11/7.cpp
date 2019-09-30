#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int z = 1; z <= T; z++) {
        int N;
        cin >> N;

        long long m[N];
        for (int i = 0; i < N; i++)
            cin >> m[i];

        long long velocity = 0, sum = 0;
        for (int i = 1; i < N; i++) {
            velocity = max(velocity, max(0LL, m[i-1] - m[i]));
            sum += max(0LL, m[i-1] - m[i]);
        }

        long long ans2 = 0;
        for (int i = 0; i+1 < N; i++) {
            long long next = m[i] - velocity;
            ans2 += m[i] - max(0LL, next);
        }

        cout << "Case #" << z << ": " << sum << " " << ans2 << endl;
    }
}
