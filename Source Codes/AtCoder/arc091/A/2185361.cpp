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

void solve(long long N, long long M){
    if (N == 1 || M == 1) {
        if (N == 1 && M == 1) {
            std::cout << 1 << std::endl;
            return;
        } else {
            std::cout << max(N, M) - 2 << std::endl;
        }
    } else {
        std::cout << (N-2) * (M-2) << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long M;
    long long N;
    scanf("%lld",&N);
    scanf("%lld",&M);
    solve(N, M);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}