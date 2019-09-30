#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<int> c(n);
    rep(i, n){
        cin >> c[i];
    }

    vector<int> seq;
    int a = 0;
    rep(i, n-1){
        if(c[i] == c[i+1]){
            a++;
        }else{
            seq.push_back(a);
            a = 0;
        }
    }

    if(a == n-1){
        cout << -1 << endl;
        return 0;
    }

    if(c[n-1] == c[0]){
        int i = 0;
        while(c[n-1] == c[i++]){
            a++;
        }
        seq.push_back(a);
    }

    int ans = *max_element(seq.begin(), seq.end());
    cout << 1 + ans / 2 << endl;

    return 0;
}