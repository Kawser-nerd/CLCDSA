#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <map>
#include <cstdint>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;


// extended Euclidean Algorithm
// ax + by = gcd(a, b)
// return : gcd(a, b)
template<typename Integer = int_fast64_t>
constexpr Integer extgcd(Integer a, Integer b, Integer &x, Integer &y){
    Integer u = 0, v = 1, q = 0, tmp = 0;
    x = v = 1;
    y = u = 0;

    while(b){
        q = a / b;
        x ^= u ^= x ^= u;
        u = u - q * x;
        y ^= v ^= y ^= v;
        v = v - q * y;
        a ^= b ^= a ^= b;
        b = b - q * a;
    }

    return a;
}

// mod inverse(?????????????)
// return : val^(-1) mod MOD
template<int_fast64_t MOD, typename Integer = int_fast64_t>
constexpr Integer modinv(Integer val){
    int_fast64_t ret = 0, tmp = 0;

    extgcd<int_fast64_t>(static_cast<int_fast64_t>(val), static_cast<int_fast64_t>(MOD), ret, tmp);

    return static_cast<Integer>(ret > 0 ? ret % MOD : (MOD - (-ret % MOD)));
}

// const expression factorial mod MOD
template<std::size_t N, std::int_fast64_t MOD>
struct Fact {
    std::int_fast64_t val[N + 1];

    constexpr Fact() : val() {
        val[0] = 1;
        for (std::size_t i = 1; i <= N; ++i) val[i] = val[i - 1] * i % MOD;
    }
};

// const expression factorial inverse mod MOD
template<std::size_t N, std::int_fast64_t MOD, std::int_fast64_t F>
struct IFact {
    std::int_fast64_t val[N + 1];

    constexpr IFact() : val() {
        val[N] = F;
        for (std::size_t i = N; i; --i) val[i - 1] = val[i] * i % MOD;
    }
};

constexpr std::int_fast64_t MOD = 1'000'000'007ll, maxN = 300000ll;

constexpr auto fact = Fact<maxN, MOD>();
constexpr auto ifact = IFact<maxN, MOD, modinv<MOD>(fact.val[maxN])>();

// const expression binomial mod MOD
constexpr std::int_fast64_t binommod(std::int_fast64_t n, std::int_fast64_t r){
    if(r < 0 || r > n)return 0;
    return fact.val[n] * (ifact.val[r] * ifact.val[n - r] % MOD) % MOD;
}


int main(){

    long long int n,m;
    cin >> n >> m;
    if(m==1){
        cout << 1 << endl;
        return 0;
    }
    map<long long int, long long int> mp;
    long long int divisor=2;

    {
        double rootm = pow(m, 0.5) + 100;
        while(m>1&&divisor<=rootm){
            if(m%divisor==0){
                m /= divisor;
                mp[divisor]++;
            }else{
                divisor++;
            }
        }
    }

    if(m!=1){
        mp[m]++;
    }
    long long int result = 1;
    for(auto x:mp){
        result *= binommod(n + x.second-1, x.second);
        result %= mod;
    }
    cout << result << endl;
    


    return 0;
} ./Main.cpp:37:21: warning: unsequenced modification and access to 'x' [-Wunsequenced]
        x ^= u ^= x ^= u;
          ~~        ^
./Main.cpp:39:21: warning: unsequenced modification and access to 'y' [-Wunsequenced]
        y ^= v ^= y ^= v;
          ~~        ^
./Main.cpp:41:21: warning: unsequenced modification and access to 'a' [-Wunsequenced]
        a ^= b ^= a ^= b;
          ~~        ^
./Main.cpp:37:21: warning: unsequenced modification and access to 'x' [-Wunsequenced]
        x ^= u ^= x ^= u;
          ~~        ^
./Main.cpp:54:5: note: in instantiation of function template specialization 'extgcd<long>' requested here
    extgcd<int_fast64_t>(static_cast<int_fast64_t>(val), static_cast<int_fast64_t>(MOD), ret, tmp);
    ^
./Main.cpp:39:21: warning: unsequenced modification and access to 'y' [-Wunsequenced]
        y ^= v ^= y ^= v;
          ~~        ^
./Main.cpp:41:21: warning: unsequenced modification and access to 'a' [-Wunsequenced]
        a ^= b ^= a ^= b;
          ~~        ^
6 warnin...