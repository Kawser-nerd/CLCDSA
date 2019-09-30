#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 1001001001;
const ll LINF = 1e18;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    T r;
    while((r=a%b)) {
        a = b; b = r;
    }
    return b;
}

string makeDigit(ll N, string res)
{
    if(N == 0)
        return res;
    
    ll l = 0, r = 0, idx = 0;
    ll nextN = N; ll maxDig = 0;
    vi v(100, 0);
    while(abs(nextN) >= 1){
        if(idx % 2 == 0) r += pow(2, idx);
        else l += - pow(2, idx);
        if(l <= nextN && nextN <= r){
            v[idx] = 1;
            maxDig = max(maxDig, idx);
            nextN = (idx % 2 == 0) ? nextN - pow(2, idx) : nextN + pow(2, idx);
            idx = 0; l = 0; r = 0;
        }
        else idx++;
    }
    
    string ret = "";
    for (int i = 0; i <= maxDig; i++) {
        ret = to_string(v[i]) + ret;
    }
    return ret;
}

int main() {
    ll N; cin >> N;
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << makeDigit(N, "") << endl;
    return 0;
}