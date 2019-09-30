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
    
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    while (1){
        if (A % 2 || B % 2 || C % 2){
            break;
        }
        if (A == B && A == C && B == C){
            cout << -1 << endl;
            return 0;
        }
        ans++;
        int tmpa = B/2 + C/2;
        int tmpb = A/2 + C/2;
        int tmpc = B/2 + A/2;
        A = tmpa;
        B = tmpb;
        C = tmpc;
    }
    cout << ans << endl;
    return 0;
}