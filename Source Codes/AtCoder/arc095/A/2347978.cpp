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

void solve(long long N, vector<long long> X){
    vector<long long> Y = X;
    sort(X.begin(), X.end());
    for (auto&& y : Y) {
        if (y < X[N/2]) {
            std::cout << X[N/2] << std::endl;
        } else {
            std::cout << X[N/2-1] << std::endl;
        }
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long N;
    scanf("%lld",&N);
    vector<long long> X(N-1+1);
    for(int i = 0 ; i <= N-1 ; i++){
    	scanf("%lld",&X[i]);
    }
    solve(N, X);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}