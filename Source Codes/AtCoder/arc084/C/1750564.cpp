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

void countdown(vector<int> &r, int k, int n, int &z) {
    //if(r[z] > 0){
    //    --r[z];
    //} else {
    //    --r[z-1];
    //    r[z] = k;
    //    if(r[z-1]==0) --z;
    //    else z = n-1;
    //}
    if (r[z] == 0) {
        r[z] = k;
        z--;
        r[z]--;
        if (r[z] != 0) {
            z = n-1;
        }
    } else if(r[z] > 0){
        r[z]--;
    } else {
        std::cerr << r[z-1] << r[z] << r[z+1] << std::endl;
    }
    return;
}

void solve(int k, int n) {
    if (k%2 == 0) {
        std::cout << k/2;
        for (int i = 0; i < n-1; i++) {
            std::cout << " " << k;
        }
        std::cout << std::endl;
        return;
    }
    vector<int> ret(n, (k+1)/2);
    int z = n-1;
    for (int i = 0; i < n/2; i++) {
        countdown(ret, k, n, z);
    }
    std::cout << ret[0];
    for (int i = 1; i < ret.size(); i++) {
        if (ret[i] == 0) {
            break;
        }
        std::cout << " " << ret[i];
    }
    std::cout << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int k, n;

    gettimeofday(&start,NULL);

    std::cin >> k >> n;
    solve(k, n);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}