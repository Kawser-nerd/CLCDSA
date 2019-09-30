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

void solve(long long N, long long K){
    if (K == 0) {
        std::cout << N*N << std::endl;
    } else {
        long long ret = 0;
        for (int i = K+1; i < N+1; i++) {
            long long a = (N/i)*(i-K) + max(0LL, (N%i) - (K-1));
            ret += a;
        }
        std::cout << ret << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long K;
    long long N;
    scanf("%lld",&N);
    scanf("%lld",&K);
    solve(N, K);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}