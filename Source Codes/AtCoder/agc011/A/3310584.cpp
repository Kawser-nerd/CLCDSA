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

Int t[1000005];

int main(){
    cin.tie(0);
    
    int N, C, K;
    cin >> N >> C >> K;
    for (int i = 0; i < N; i++){
        cin >> t[i];
    }
    sort(t, t+N);
    int i = 1;
    int crt = t[0];
    int cnt = 1;
    int ans = 0;
    while (i < N){
        if (crt + K >= t[i] && cnt < C){
            cnt++;
        }else{
            crt = t[i];
            cnt = 1;
            ans++;
        }
        i++;
    }
    ans++;
    cout << ans << endl;
}