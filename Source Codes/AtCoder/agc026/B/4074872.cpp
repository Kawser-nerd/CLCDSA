#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
//???
void Y(){
    cout << "Yes" << endl;
}
void N(){
    cout << "No" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a < b or d < b){
            N();
            continue;
        }
        if(c >= b-1){
            Y();
            continue;
        }
        //B<=A,B<=D,C<B
        ll g = __gcd(b,d);
        ll ma = b-g+a%g;
        if(ma > c){
            N();
        }else{
            Y();
        }
    }
}