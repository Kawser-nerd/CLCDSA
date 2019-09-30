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

Int a[300005];

int check(int i){
    if (a[i] > a[i-1]) return 1;
    else if (a[i] == a[i-1]) return 0;
    else return -1;
}

int main(){
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    int ans = 1;
    if (N == 1 || N == 2){
        cout << ans << endl;
        return 0;
    }
    int flag1 = 0;
    for (int i = 2; i < N; i++){
        if (flag1 == 0) flag1 = check(i-1);
        int flag2 = check(i);
        if (flag1 * flag2 == -1){
            ans++;
            i++;
            flag1 = 0;
        }
    }
    cout << ans << endl;
    return 0;
}