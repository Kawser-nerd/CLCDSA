#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

using ll = long long;
const ll inf = 1LL << 60;

ll f(int w, vector<pair<int, int>> cq) {
    
    if (cq.empty()) {
        return 0;
    }
    
    sort(cq.begin(), cq.end());
    
    map<int, vector<int>> m;
    
    for (int i = 0; i < cq.size(); ++i) {
        m[cq[i].first].push_back(cq[i].second);    
    }
    
    vector<ll> dp(w);
    
    for (auto& q : m) {
        vector<pair<int, int>> range;
        
        range.emplace_back(q.second.front(), q.second.front());
        
        for (int i = 1; i < q.second.size(); i++) {
            if (q.second[i] == range.back().second + 1) {
                range.back().second++;   
            } else {
                range.emplace_back(q.second[i], q.second[i]);   
            }
        }
        
        for (auto r : range) {
            for (int i = r.first; i <= r.second; i++) {
                if (r.first > 0) {
                    dp[r.first - 1] = min(dp[r.first - 1], dp[i] + i - r.first + 1);
                }
                
                if (r.second < w - 1) {
                    dp[r.second + 1] = min(dp[r.second + 1], dp[i] + r.second + 1 - i);
                }
                                          
                dp[i] = inf;
            }
        }
        
    }
    
    return *min_element(dp.begin(), dp.end());
}

int main() {
    
    int w, h, q;
    cin >> w >> h >> q;
    
    vector<pair<int, int>> rq, cq;
    
    for (int i = 0; i < q; i++) {
        int t, d, x;
        
        cin >> t >> d >> x;
        
        x--;
        
        if (d == 0) {
            cq.emplace_back(t, x);   
        } else {
            rq.emplace_back(t, x);
        }
    }
    
    auto ans = f(w, cq);
    
    ans += f(h, rq);
    
    if (ans < inf) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}