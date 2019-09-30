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

void swap(long long& r, long long& l){
    if (r > l) {
        return;
    } else {
        long long tmp = r;
        r = l;
        l = tmp;
        return;
    }
}

void solve(long long A, long long B, long long C){
    swap(A, B);
    swap(A, C);
    long long sAB = A - B;
    long long sAC = A - C;
    long long ret = sAB/2 + sAC/2;
    if ((sAB%2 == 0) && (sAC%2 == 0)) {
        
    } else if((sAB%2 == 1) && (sAC%2 == 0)) {
        ret += 2;
    } else if((sAB%2 == 0) && (sAC%2 == 1)) {
        ret += 2;
    } else if((sAB%2 == 1) && (sAC%2 == 1)) {
        ret += 1;
    }
    std::cout << ret << std::endl;
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long A;
    long long B;
    long long C;
    scanf("%lld",&A);
    scanf("%lld",&B);
    scanf("%lld",&C);
    solve(A, B, C);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}