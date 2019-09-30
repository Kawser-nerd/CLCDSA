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

Int a[100005];
vector<string> s;
int main(){
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++){
        string tmp; cin >> tmp;
        s.push_back(tmp);
    }

    Int ans = 0;
    for (int i = 0; i < N; i++){
        int flag = 1;
        for (int j = 0; j < N; j++){
            for (int k = i; k < i + N; k++){
                if (s[j][k%N] != s[k-i][(i+j)%N]) flag = 0;
            }
        }
        if (flag) ans += N;
    }

    cout << ans << endl;

}