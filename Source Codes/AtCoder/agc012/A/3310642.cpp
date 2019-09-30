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

Int ans;
Int a[300005];

int main(){
    cin.tie(0);
    
    int N;
    cin >> N;
    N *= 3;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    int left = 0;
    int mid = N-2;
    int right = N-1;
    while (left < mid && mid < right){
        ans += a[mid];
        mid -= 2;
        right -= 2;
        left += 1;
    }
    cout << ans << endl;
}