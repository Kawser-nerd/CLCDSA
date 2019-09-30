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

void solve(long long N, vector<long long> a){
    bool odd;
    long long odd_v = 0;
    long long even_v = 0;
    int r;
    int l = 0;
    vector<int> ret;
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) {
            if (i%2 == 0) {
                even_v += a[i];
            } else {
                odd_v += a[i];
            }
        }
    }
    if (even_v == 0 && odd_v == 0) {  // when all negative
        long long ret_v = (long long)-1e11;
        int ret_idx;
        for (int i = 0; i < N; i++) {
            if (a[i] > ret_v) {
                ret_v = a[i];
                ret_idx = i;
            }
        }
        std::cout << ret_v << std::endl;
        std::cout << N-1 << std::endl;
        for (int i = N; i > ret_idx+1; i--) {
            std::cout << i << std::endl;
        }
        for (int i = 0; i < ret_idx; i++) {
            std::cout << 1 << std::endl;
        }
        return;
    }

    if (even_v > odd_v) {
        odd = false;
    } else {
        odd = true;
    }
    while (r < N) {
        if (odd) {
            if (a[l] < 0 || l%2 == 0) {
                ret.push_back(1);
                l++;
            } else {
                r = l+2;
                break;
            }
        } else {
            if (a[l] < 0 || l%2 == 1) {
                ret.push_back(1);
                l++;
            } else {
                r = l+2;
                break;
            }
        }
    }
    while (r < N-1) {
        if(a[r] < 0) {
            ret.push_back(3);
            r += 2;
        } else {
            ret.push_back(2);
            r += 2;
        }
    }
    if (r == N-1) {
        if (a[r] < 0) {
            ret.push_back(3);
            ret.push_back(2);
        } else {
            ret.push_back(2);
        }
    } else {
        ret.push_back(2);
    }
    if (odd) {
        std::cout << odd_v << std::endl;
    } else {
        std::cout << even_v << std::endl;
    }
    std::cout << ret.size() << std::endl;
    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long N;
    scanf("%lld",&N);
    vector<long long> a(N-1+1);
    for(int i = 0 ; i <= N-1 ; i++){
    	scanf("%lld",&a[i]);
    }
    solve(N, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}