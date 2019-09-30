#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static const int kModulo = 998'244'353;

int pow(int x, int y) {
    if (y == 0)
        return 1;
    if (y % 2)
        return 1LL * pow(x, y - 1) * x % kModulo;
    int v = pow(x, y / 2);
    return 1LL * v * v % kModulo;
}

int main() {
    ios::sync_with_stdio(false);

    int N, A, B; int64_t K; cin >> N >> A >> B >> K;

    vector<int> fact(N + 1), ifact(N + 1);
    fact[0] = ifact[0] = 1;
    fact[1] = ifact[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % kModulo;
        ifact[i] = pow(fact[i], kModulo - 2);
    }

    auto comb = [&](int N, int K) {
        int aux = 1LL * fact[N] * ifact[K] % kModulo;
        return 1LL * aux * ifact[N - K] % kModulo;
    };

    int answer = 0;
    for (int x = 0; x <= N; ++x) {
        int64_t left = K - 1LL * x * A;
        if (left < 0)
            break;
        if (left % B)
            continue;
        int64_t y = left / B;
        if (y > N)
            continue;
        answer = (answer + 1LL * comb(N, x) * comb(N, y)) % kModulo;
    }

    cout << answer << "\n";
}