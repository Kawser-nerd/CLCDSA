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

void solve(long long N, long long A, long long B){
    if (N < A+B-1 || N > A*B) {
        std::cout << -1 << std::endl;
        return;
    } else {
        vector<int> ret(N);
        int i = 0;
        for (int j = 0; j < A; j++) {
            ret[i] = N - A + j + 1;
            i++;
        }
        if (A == N) {
            for (int j = 0; j < N-1; j++) {
                std::cout << ret[j] << ' ';
            }
            std::cout << ret[N-1] << std::endl;
            return;
        }
        for (int j = 0; j < (N - A)/(B-1); j++) {
            int a = (j+1)*(B-1);
            for (int k = 0; k < B-1; k++) {
                ret[i] = a;
                a--;
                i++;
                if (i == N) {
                    break;
                }
            }
        }
        int l = N-i;
        for (int j = 0; j < l; j++) {
            ret[i] = ret[0] - 1 - j;
            i++;
        }
        for (int j = 0; j < N-1; j++) {
            std::cout << ret[j] << ' ';
        }
        std::cout << ret[N-1] << std::endl;
        return;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long A;
    long long B;
    long long N;
    scanf("%lld",&N);
    scanf("%lld",&A);
    scanf("%lld",&B);
    solve(N, A, B);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}