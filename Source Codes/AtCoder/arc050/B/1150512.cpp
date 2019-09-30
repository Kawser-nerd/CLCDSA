#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

ll R, B;
ll x, y;

bool query(ll i){
    if (R < i || B < i) return false;
    ll f = (R-i) / (x-1) + (B-i) / (y-1);
    return f >= i;
}

ll binarySearch(ll left, ll right){

    while (left < right){
        ll mid = (left + right) / 2;
        bool b = query(mid);
        fprintf(stderr, "%d %d %d %d\n", left, right, mid, b);
        if (b){
            left = mid;
        }
        else{
            right = mid;
        }
        if(left + 1 == right) return left;
    }
    return -1;
}

int main() {

    cin >> R >> B;
    cin >> x >> y;
    cout << binarySearch(0, R+1) << endl;
} ./Main.cpp:39:42: warning: format specifies type 'int' but the argument has type 'll' (aka 'long long') [-Wformat]
        fprintf(stderr, "%d %d %d %d\n", left, right, mid, b);
                         ~~              ^~~~
                         %lld
./Main.cpp:39:48: warning: format specifies type 'int' but the argument has type 'll' (aka 'long long') [-Wformat]
        fprintf(stderr, "%d %d %d %d\n", left, right, mid, b);
                            ~~                 ^~~~~
                            %lld
./Main.cpp:39:55: warning: format specifies type 'int' but the argument has type 'll' (aka 'long long') [-Wformat]
        fprintf(stderr, "%d %d %d %d\n", left, right, mid, b);
                               ~~                     ^~~
                               %lld
3 warnings generated.