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

void solve(long long N, vector<long long> t, vector<long long> x, vector<long long> y){
    long long dist = abs(0 - x[0]) + abs(0-y[0]);
    long long time = t[0] - 0;
    for (int i = 0; i < N-1; i++) {
        if (dist <= time && (dist-time)%2 == 0) {
            dist = abs(x[i] - x[i+1]) + abs(y[i] - y[i+1]);
            time = t[i+1] - t[i];
        } else {
            std::cout << "No" << std::endl;
            return;
        }
    }
    if (dist <= time && (dist-time)%2 == 0) {
        std::cout << "Yes" << std::endl;
        return;
    } else {
        std::cout << "No" << std::endl;
        return;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long N;
    scanf("%lld",&N);
    vector<long long> x(N-1+1);
    vector<long long> y(N-1+1);
    vector<long long> t(N-1+1);
    for(int i = 0 ; i <= N-1 ; i++){
    	scanf("%lld",&t[i]);
    	scanf("%lld",&x[i]);
    	scanf("%lld",&y[i]);
    }
    solve(N, t, x, y);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}