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

Int mod_pow(Int x, Int n){
    Int res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
    return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
    Int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

int bits[200005][21];
int a[200005];

int main(){
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        for (int j = 0; j < 21; j++){
            if (a[i] & (1 << j)){
                bits[i][j] = 1;
            }
        }
    }
    Int ans = 0;
    int right = 0;
    set<int> s;
    for (int left = 0; left < N; left++){
        while (right < N){
            int flag = 1;
            for (int i = 0; i < 21; i++){
                if (bits[right][i] && s.count(i)){
                    flag = 0;
                }
            }
            if (flag){
                for (int i = 0; i < 21; i++){
                    if (bits[right][i]){
                        s.insert(i);
                    }
                }
                ans += (right - left + 1);
                right++;
            }else{
                break;
            }
        }
        for (int i = 0; i < 21; i++){
            if (bits[left][i]){
                s.erase(i);
            }
        }
    }

    cout << ans << endl;
    return 0;
}