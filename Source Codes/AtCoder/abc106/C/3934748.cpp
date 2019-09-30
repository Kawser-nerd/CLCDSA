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

int main() {
    string S; ll K; cin >> S >> K;

    bool isOne = true;
    ll minInd = LINF;
    for(ll i = 0; i < min((ll)S.size(), K); i++){
        if(S[i] != '1'){
            isOne = false;
            minInd = i;
            break;
        }
    }
    
    cout << (isOne ? '1' : S[minInd]) << endl;
    return 0;
}