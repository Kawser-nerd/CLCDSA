#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
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
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //?????(???????1???)
        x = (x * x) % MOD;
        n >>= 1; //????(n = n >> 1)
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

Int S[51];
Int P[51];

Int calc(int n, Int x){
    if (x == 1 || x == 0){
        return 0;
    }
    if (x == S[n-1] + 1){
        return P[n-1];
    }

    if (x >= (S[n]+1) / 2) return P[n] - calc(n, S[n] - x);
    else return calc(n-1, x-1);
}


int main(){
    cin.tie(0);

    Int N, X; cin >> N >> X;
    
    P[0] = 1LL;
    S[0] = 1LL;

    for (int i = 1; i <= N; i++){
        S[i] = S[i-1]*2LL+3LL;
        P[i] = P[i-1]*2LL+1LL;
    }

    cout << calc(N, X) << endl;
}