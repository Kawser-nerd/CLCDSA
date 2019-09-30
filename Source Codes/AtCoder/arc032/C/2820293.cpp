#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
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
    vector<pair<P, int>> task;
    vector<P> toTask(n+1);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        toTask[i+1] = make_pair(a, b);
        task.emplace_back(toTask[i+1], i+1);
    }
    sort(task.begin(), task.end());

    vector<P> dp(1e6+1); //<????, ???>
    int job = n-1;
    for(int t = 1e6-1; t >= 0; t--){
        dp[t] = dp[t+1];

        while(job >= 0 && t == task[job].first.first){
            int last = task[job].first.second;
            if(dp[t].second == dp[last].second + 1){
                dp[t].first = min(dp[t].first, task[job].second);
            }
            if(dp[t].second < dp[last].second + 1){
                dp[t].first = task[job].second;
                dp[t].second = dp[last].second + 1;
            }
            job--;
        }
    }

    /*
    rep(i, 20){
        cout << dp[i].first << " " << dp[i].second << endl;
    }
    */

    int next = dp[0].first;
    vector<int> list;
    rep(i, dp[0].second){
        list.push_back(next);
        int t = toTask[next].second;
        next = dp[t].first;
    }
    cout << dp[0].second << endl;
    for(int i = 0; i < (int)list.size()-1; i++){
        cout << list[i] << " ";
    }
    cout << list[list.size()-1] << endl;

    return 0;
}