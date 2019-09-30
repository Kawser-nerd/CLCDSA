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

void solve(long long A, long long B){
    vector< vector<char> > ret(96, vector<char>(99, '.'));
    for (int i = 0; i < 48; i++) {
        for (int j = 0; j < 99; j++) {
            ret[i][j] = '#';
        }
    }
    A--;
    B--;
    int x = 1;
    int y = 1;
    while (A > 0) {
        ret[x][y] = '.';
        A--;
        x += 2;
        if (x >= 47) {
            y += 2;
            x = 1;
        }
    }
    x = 49;
    y = 1;
    while (B > 0) {
        ret[x][y] = '#';
        B--;
        x += 2;
        if (x >= 95) {
            y += 2;
            x = 49;
        }
    }
    std::cout << 96 << ' ' << 99 << std::endl;
    for (int i = 0; i < 96; i++) {
        for (int j = 0; j < 99; j++) {
            std::cout << ret[i][j];
        }
        std::cout << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long A;
    long long B;
    scanf("%lld",&A);
    scanf("%lld",&B);
    solve(A, B);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}