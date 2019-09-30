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

//?????
template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

//?????
template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

Int h[100005];

int main(){
    cin.tie(0);

    int N; cin >> N;
    int K; cin >> K;
    for (int i = 0; i < N; i++){
        cin >> h[i];
    }
    sort(h, h+N);
    Int ans = 10000000000;
    for (int i = 0; i < N-K+1; i++){
        ans = min(ans, h[i+K-1]-h[i]);
    }
    cout << ans << endl;

}