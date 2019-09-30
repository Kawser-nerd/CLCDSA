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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int len = 0;
    int j = 0;
    set<int> s;
    for(int i = 0; i < n; i++){
        while(s.find(a[i]) != s.end()){
            s.erase(a[j++]);
        }

        s.insert(a[i]);
        if((int)s.size() > len){
            len = s.size();
        }
    }
    cout << len << endl;

    return 0;
}