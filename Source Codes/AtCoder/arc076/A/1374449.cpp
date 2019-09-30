#include <iostream>
#include <algorithm>
#define _ %1000000007

typedef long long LL;
using namespace std;

int compute(int M, int D) {
    if (abs(M-D) > 1) return 0;
    int tiny = min(M, D);
    LL ret = 1;
    for (LL item = tiny; item >= 2; item--) {
        ret = (item*ret)_;
    }
    ret = (ret*ret)_;
    if(M == D) {
        ret = (ret<<1)_;
    }
    else {
        int big = max(M, D);
        ret = (ret*big)_;
    }
    return ret;


}

int main() {
    int m,d;
    cin >> m >> d;
    int ret = compute(m, d);
    cout << ret << endl;

    return 0;
}