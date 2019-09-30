#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

void solve(int n, int z, int w, vector<int> a) {
    vector< vector<int> > dp(2, vector<int> (n, 0));
    if (n == 1) {
        std::cout << abs(a[0] - w) << std::endl;
        return;
    }
    dp[0][n-1] = abs(a[n-2] - a[n-1]);
    dp[1][n-1] = abs(a[n-2] - a[n-1]);
    for (int i = n-2; i > 0; i--) {
        int tmp = *max_element(dp[1].begin()+i+1, dp[1].end());
        tmp = max(tmp, abs(a[i-1]-a[n-1]));
        dp[0][i] = tmp;
        tmp = *min_element(dp[0].begin()+i+1, dp[0].end());
        tmp = min(tmp, abs(a[i-1]-a[n-1]));
        dp[1][i] = tmp;
    }
    dp[0][0] = max(*max_element(dp[1].begin()+1, dp[1].end()), abs(w-a[n-1]));
    std::cout << dp[0][0] << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n, z, w;

    gettimeofday(&start,NULL);

    std::cin >> n >> z >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    solve(n, z, w, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}