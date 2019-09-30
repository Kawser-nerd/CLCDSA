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

Int a[200005];
int main(){
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    Int ans = 0;
    Int crt = 0;
    for (int i = N-1; i >= 0; i--){
        if (crt > a[i] || a[i] > i){
            ans = -1;
            break;
        }
        if (crt < a[i]){
            ans += a[i];
            crt = a[i];
        }
        crt--;
    }
    cout << ans << endl;
}