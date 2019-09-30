#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>

#define BIT(a) (1 << (a))

using namespace std;

long long MOD = 1000000007;


long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main(void){
    long long N, K;
    cin >> N >> K;
    double ans = 6*(N-K)*(K-1)+3*(N-1)+1;
    ans /= pow(N, 3);
    printf("%.20f\n", ans);
    return 0;
}