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


int main(){
    cin.tie(0);
    Int N, X; cin >> N >> X;
    
    Int ans = 0;
    Int crt;
    Int pre;
    if (X*2 < N){
        ans += X+(N-X);
        crt = X;
        pre = N-X;
    }else if(X*2 > N){
        ans += X+(N-X);
        crt = N-X;
        pre = X;
    }else if(X*2 == N){
        ans += 3*X;
        cout << ans << endl;
        return 0;
    }

    while (pre % crt){
        ans += pre/crt*2*crt;
        Int tmp = crt;
        crt = pre%crt;
        pre = tmp;
    }
    ans += pre*2-crt;
    cout << ans << endl;

}