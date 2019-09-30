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

void solve(long long N, vector<long long> A){
    vector<long long> s(N);
    s[0] = (abs(A[0] - 0) + abs(A[1] - A[0])) - abs(A[1] - 0);
    s[N-1] = (abs(A[N-1] - A[N-2]) + abs(0 - A[N-1])) - abs(A[N-2] - 0);
    for (int i = 1; i < N-1; i++) {
        s[i] = (abs(A[i] - A[i-1]) + abs(A[i+1] - A[i])) - abs(A[i+1] - A[i-1]);
    }
    long long tot = 0;
    tot += abs(A[0] - 0) + abs(0 - A[N-1]);
    for (int i = 0; i < N-1; i++) {
        tot += abs(A[i+1] - A[i]);
    }
    for (int i = 0; i < N; i++) {
        std::cout << tot - s[i] << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long N;
    scanf("%lld",&N);
    vector<long long> A(N-1+1);
    for(int i = 0 ; i <= N-1 ; i++){
    	scanf("%lld",&A[i]);
    }
    solve(N, A);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}