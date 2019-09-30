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

void solve(long long N, vector<string> S){
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                int x1 = (j + i) % N;
                int y1 = k;
                int x2 = (k + i) % N;
                int y2 = j;
                if (x1 == y1) {
                    continue;
                }
                if (S[x1][y1] != S[x2][y2]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            ret++;
        }
    }
    std::cout << ret*N << std::endl;
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long N;
    scanf("%lld",&N);
    vector<string> S(N-1+1);
    for(int i = 0 ; i <= N-1 ; i++){
    	cin >> S[i];
    }
    solve(N, S);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}