#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string MINUSINF = "-";

void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

long long match[10] = {2,5,5,4,5,6,3,7,6};
string dp[11000];

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) cin >> A[i];

    // ???
    for (int i = 0; i < 11000; ++i) dp[i] = MINUSINF;

    // ????
    dp[0] = "";

    // DP ???
    for (int i = 0; i <= N; ++i) {
        if (dp[i] == MINUSINF) continue;
        for (auto a : A)  chmax(dp[i+match[a-1]], dp[i] + (char)('0' + a));
    }
    cout << dp[N] << endl;
}