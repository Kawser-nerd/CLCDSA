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
#include <bitset>

using namespace std;

void solve(int n, vector<long long> a1, vector<long long> a2) {
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        long long s1 = 0;
        for (int j = 0; j < i+1; j++) {
            s1 += a1[j];
        }
        long long s2 = 0;
        for (int j = n-1; j > i-1; j--) {
            s2 += a2[j];
        }
        if (ret < s1+s2) {
            ret = s1+s2;
        }
    }
    std::cout << ret << std::endl;

}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector<long long> a1(n);
    vector<long long> a2(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a1[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a2[i];
    }
    solve(n, a1, a2);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}