#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    int na, nb;
    cin >> na >> nb;

    set<int> a;
    rep(i, na){
        int aa;
        cin >> aa;
        a.insert(aa);
    }

    int c = 0;
    rep(i, nb){
        int b;
        cin >> b;
        if(a.find(b) != a.end()){
            c++;
        }
    }
    cout << fixed << setprecision(7) << (double)c / (double)(na + nb - c) << endl;

    return 0;
}