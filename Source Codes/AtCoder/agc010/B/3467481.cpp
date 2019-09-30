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
Int b[100005];

int main(){
    cin.tie(0);

    Int N; cin >> N;
    Int SUM = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        SUM += a[i];
    }
    for (int i = 0; i < N; i++){
        if (i == N-1){
            b[i] = a[0] - a[i];
            continue;
        }
        b[i] = a[i+1] - a[i];
    }
    if (SUM % ((N+1)*N/2)){
        cout << "NO" << endl;
        return 0;
    }
    Int CNT = SUM / ((N+1)*N/2);
    for (int i = 0; i < N; i++){
        b[i] -= CNT;
    }
    Int cnt = 0;
    for (int i = 0; i < N; i++){
        if (b[i] <= 0){
            if (b[i] % (-N) == 0){
            cnt += b[i] / (-N);
            }else{
                cout << "NO" << endl;
                return 0;
            }
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    if (cnt > CNT){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}