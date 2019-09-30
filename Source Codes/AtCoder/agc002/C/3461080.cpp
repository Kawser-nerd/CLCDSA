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

int main(){
    Int N; cin >> N;
    Int L; cin >> L;

    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    for (int i = 0; i < N-1; i++){
        if (a[i] + a[i+1] >= L){
            cout << "Possible" << endl;
            for (int j = 0; j < i; j++){
                cout << j+1 << endl;
            }
            for (int j = N-2; j > i; j--){
                cout << j+1 << endl;
            }
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}