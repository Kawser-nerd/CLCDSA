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
    bool odd = true;
    long long odd_v = 0;
    long long even_v = 0;
    int r;
    int l;
    vector<int> ret;
    for (int i = 0; i < N; i+=2) {
        if (a[i] > 0) {
            even_v += a[i];
        }
    }
    for (int i = 1; i < N; i+=2) {
        if (a[i] > 0) {
            odd_v += a[i];
        }
    }
    if (even_v == 0 && odd_v == 0) {
        even_v = (long long)-1e11;
        odd_v = (long long)-1e11;
        int ret_num_e = 0;
        int ret_num_o = 0;
        for (int i = 0; i < N; i+=2) {
            if (a[i] > even_v) {
                even_v = a[i];
                ret_num_e = i;
            }
        }
        for (int i = 1; i < N; i+=2) {
            if (a[i] > odd_v) {
                odd_v = a[i];
                ret_num_o = i;
            }
        }
        long long ret_t, ret_num;
        if (even_v > odd_v) {
            ret_t = even_v;
            ret_num = ret_num_e;
        } else {
            ret_t = odd_v;
            ret_num = ret_num_o;
        }
        std::cout << ret_t << std::endl;
        std::cout << N-1 << std::endl;
        for (int i = N; i > ret_num+1; i--) {
            std::cout << i << std::endl;
        }
        for (int i = 0; i < ret_num; i++) {
            std::cout << 1 << std::endl;
        }
        return;
    }
    if (even_v > odd_v) {
        odd = false;
    }
    if (odd) {
        ret.push_back(1);
        r = 1;
        l = 3;
    } else {
        r = 0;
        l = 2;
    }
    bool flag = true;
    while (l < N-1) {
        if (a[r] < 0 && flag) {
            ret.push_back(1);
            ret.push_back(1);
            r += 2;
            l += 2;
        } else if(a[l] < 0) {
            ret.push_back(3);
            l += 2;
            flag = false;
        } else {
            ret.push_back(2);
            r += 2;
            l += 2;
            flag = false;
        }
    }
    if (l == N-1) {
        if (a[l] < 0) {
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