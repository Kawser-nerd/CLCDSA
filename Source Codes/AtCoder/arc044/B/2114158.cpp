#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;
const int mod = 1e9+7;

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % mod, n / 2);
    }
    return powM(x, n-1) * x % mod;
}

signed main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]]++;
    }
    int aMax = *max_element(a.begin(), a.end());

    if(a[0] != 0 || b[0] > 1){
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    for(int i = 1; i <= aMax; i++){
        if(b[i] == 0){
            cout << 0 << endl;
            return 0;
        }

        ans = ans * powM(2, b[i] * (b[i] - 1) / 2) % mod;
        int x = powM(2, b[i-1]) - 1;
        for(int j = 0; j < b[i]; j++){
            ans = ans * x % mod;
        }
    }

    cout << ans << endl;

    return 0;
}