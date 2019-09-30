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
    int n, r;
    cin >> n >> r;

    vector<bool> s(n, false);
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'o'){
            s[i] = true;
        }
    }

    int last;
    for(int i = 0; i < n; i++){
        if(s[i]){
            continue;
        }
        last = i;
    }
    int ans = max(last - r + 1, (int)0);

    for(int i = 0; i < n; i++){
        if(s[i]){
            continue;
        }
        for(int j = i; j < min(i+r, n); j++){
            s[j] = true;
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}