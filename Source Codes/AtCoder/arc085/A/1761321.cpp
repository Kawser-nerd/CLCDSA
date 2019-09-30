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

void solve(int n, int m) {
    int rinv = 1 << m;
    int ms = 1900 * m + 100 * (n-m);
    std::cout << rinv * ms << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n, m;

    gettimeofday(&start,NULL);

    std::cin >> n >> m;
    solve(n, m);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}