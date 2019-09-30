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

    vector<P> red(n), blue(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        red[i] = make_pair(a, b);
    }
    rep(i, n){
        int a, b;
        cin >> a >> b;
        blue[i] = make_pair(a, b);
    }

    sort(blue.begin(), blue.end());

    vector<P> edge;
    int ans = 0;
    rep(i, n){
        int rr = -1;
        for(int j = 0; j < (int)red.size(); j++){
            if(blue[i].first > red[j].first && blue[i].second > red[j].second){
                if(rr == -1 || red[rr].second < red[j].second){
                    rr = j;
                }
            }
        }
        if(rr != -1){
            red.erase(red.begin()+rr);
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}