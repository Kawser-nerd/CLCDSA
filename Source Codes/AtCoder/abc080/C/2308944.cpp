#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<vector<int> > F(n, vector<int>(10));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    vector<vector<int> > P(n, vector<int>(11));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            scanf("%d", &P[i][j]);
        }
    }

    long long max_profit = INT_MIN;
    for (int i = 1; i < (1 << 10); i++) {
        long long profit = 0LL;
        for (int j = 0; j < n; j++) {
            int overlap = 0;
            for (int k = 0; k < 10; k++) {
                if (((i >> k) & F[j][k]) == 1) {
                    overlap++;
                }
            }
            profit += (long long)P[j][overlap];
        }
        max_profit = max(profit, max_profit);
    }

    printf("%lld\n", max_profit);

    return 0;
}