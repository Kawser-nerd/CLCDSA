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
#include <map>

using namespace std;

void solve(long long N, vector<long long> a){
    vector<long long> c((int)1e5+1, 0);
    vector<long long> b((int)1e5+1, 0);
    map<int, int> d;
    long long ret = 0;
    int j = 0;
    for (auto&& x : a) {
        if (d.find(x) == d.end()) {
            c[j]++;
            b[j] = x;
            d[x] = j;
            j++;
        } else {
            c[d[x]]++;
        }
    }
    for (int i = 0; i < 1e5+1; i++) {
        if (b[i] == 0) {
            break;
        }
        if (c[i] != b[i] && c[i] != 0) {
            if (b[i] > c[i]) {
                ret += c[i];
            } else {
                ret += c[i] - b[i];
            }
        }
    }
    std::cout << ret << std::endl;
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