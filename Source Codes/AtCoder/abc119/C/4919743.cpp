#include <iostream>
#include <vector>
#include <climits>
#include <numeric>
#include <algorithm>
#include <utility>
using namespace std;

using LL = long long;

int main() {
    int N;
    cin >> N;
    
    vector<int> ABC(3);
    for(int i = 0; i < 3; i++) cin >> ABC[i];
    
    vector<int> l(N);
    for(int i = 0; i < N; i++) cin >> l[i];
    
    int ans = INT_MAX;
    
    for(int bit = 0; bit < (1 << (2 * N)); bit++) {
        vector<vector<int>> d(4, vector<int>());
        for(int i = 0; i < N; i++) d[(bit >> (2 * i) & 3)].push_back(l[i]);
        bool good = true;
        for(int i = 0; i < 3; i++) if(d[i].size() == 0) good = false;
        if(!good) continue;
        vector<int> cost(3, 0);
        for(int i = 0; i < 3; i++) {
            cost[i] += 10 * (d[i].size() - 1);
            cost[i] += abs(ABC[i] - accumulate(d[i].begin(), d[i].end(), 0));
        }
        ans = min(ans, accumulate(cost.begin(), cost.end(), 0));
    }
    
    cout << ans << endl;
    
}