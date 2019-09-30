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

void solve(long long K, vector<long long> A){
    if (A.back() != 2) {
        std::cout << -1 << std::endl;
        return;
    }
    pair<long long, long long> ret = make_pair(2, 3);
    pair<long long, long long> tmp;
    for (int i = A.size() - 2; i >= 0; i--) {
        if (A[i] > ret.second) {
            std::cout << -1 << std::endl;
            return;
        }
        tmp.first = ((ret.first-1)/A[i] + 1)*A[i];
        tmp.second = (ret.second/A[i] + 1)*A[i] - 1;
        if (tmp.first > ret.second) {
            std::cout << -1 << std::endl;
            return;
        }
        if (tmp.second+1-A[i] < ret.first) {
            std::cout << -1 << std::endl;
            return;
        }
        ret.first = tmp.first;
        ret.second = tmp.second;
        if (ret.first > ret.second) {
            std::cout << -1 << std::endl;
            return;
        }
    }
    if (ret.first > ret.second) {
        std::cout << -1 << std::endl;
        return;
    }
    std::cout << ret.first << " " << ret.second << std::endl;
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long K;
    scanf("%lld",&K);
    vector<long long> A(K-1+1);
    for(int i = 0 ; i <= K-1 ; i++){
    	scanf("%lld",&A[i]);
    }
    solve(K, A);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}