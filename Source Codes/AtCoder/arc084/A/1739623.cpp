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

void solve(int n, vector<long long> a, vector<long long> b, vector<long long> c) {
    vector<long long> sec(n);
    vector<long long> fir(n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sec[0] = lower_bound(a.begin(), a.end(), b[0]) - a.begin();
    for (int i = 1; i < n; i++) {
        sec[i] = sec[i-1] + lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    }
    int tar = lower_bound(b.begin(), b.end(), c[0]) - b.begin() - 1;
    fir[0] = tar < 0 ? 0 : sec[tar];
    for (int i = 1; i < n; i++) {
        tar = lower_bound(b.begin(), b.end(), c[i]) - b.begin() - 1;
        fir[i] = tar < 0 ? 0 : fir[i-1] + sec[tar];
    }
    std::cout << fir[n-1] << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    solve(n, a, b, c);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}