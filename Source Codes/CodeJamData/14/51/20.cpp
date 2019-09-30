#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int64;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCases;
    cin >> testCases;
    for (int test = 1; test <= testCases; ++test) {
        int n, p, q, r, s;
        cin >> n >> p >> q >> r >> s;
        vector<int64> sum = vector<int64>(n + 1, 0);
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + (1LL * i * p + q) % r + s;
        double answer = 0.0;
        for (int l = 1, r = 1; r <= n; ++r) {
            for (; l < r && max(sum[l], sum[r] - sum[l]) <= max(sum[l - 1], sum[r] - sum[l - 1]); ++l);
            answer = max(answer, (1.0 * sum[n] - max(sum[n] - sum[r], max(sum[l - 1], sum[r] - sum[l - 1]))) / (1.0 * sum[n]));
        }
        cout << "Case #" << test << ": " << fixed << setprecision(10) << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
