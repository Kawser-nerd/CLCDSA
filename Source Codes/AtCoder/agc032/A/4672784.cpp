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

int a[105];
int cnt[105];
vector<int> ans;

int main(){
    cin.tie(0); 
    int N; cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> a[i];
        cnt[i] = i;
    }
    for (int i = N; i >= 1; i--){
        for (int j = N; j >= 1; j--){
            int flag = 0;
            if (a[j] == cnt[j]){
                ans.push_back(a[j]);
                for (int k = j; k <= N; k++){
                    cnt[k]--;
                }
                flag = 1;
            }
            if (flag) break;
        }
    }
    if (ans.size() != N){
        cout << -1 << endl;
        return 0;
    }
    for (int i = ans.size()-1; i >= 0; i--){
        cout << ans[i] << endl;
    }

    return 0;
}