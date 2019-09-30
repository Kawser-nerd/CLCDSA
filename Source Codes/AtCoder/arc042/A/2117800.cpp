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

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(m), ans;
    vector<bool> b(n+1, true);
    for(int i = m-1; i >= 0; i--){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        if(b[a[i]]){
            ans.push_back(a[i]);
            b[a[i]] = false;
        }
    }

    for(int i = 1; i <= n; i++){
        if(b[i]){
            ans.push_back(i);
        }
    }

    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}