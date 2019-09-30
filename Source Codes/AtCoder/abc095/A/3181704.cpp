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

Int mod_pow(Int x, Int n){
    Int res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
    return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
    Int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}




int main(){
    string S;
    cin >> S;
    int ans = 700;
    for (int i = 0; i < 3; i++){
        if (S[i] == 'o') ans += 100;
    }
    cout << ans << endl;
    return 0;
}