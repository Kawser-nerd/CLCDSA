#include <cstdio>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const long long MOD = 1000002013;

long long n, m;

long long GetCost(long long from, long long to) {
    long long len = to - from;
    long long first = n;
    long long last = n - len + 1;
    long long ans;
    if (len % 2 == 0) {
        return (((first + last) % MOD) * (len / 2)) % MOD;
    } else {
        return ((((first + last) / 2) % MOD) * len) % MOD;
    }
}

void solve(int case_num) {
    cin >> n >> m;
    vector<pair<long long, long long> > events;
    long long OPT = 0;
    for (int i = 0; i < m; ++i) {
        long long o, e, p;
        cin >> o >> e >> p;
        events.push_back(make_pair(o, -p));
        events.push_back(make_pair(e, p));
        OPT = (OPT + ((GetCost(o, e) % MOD) * (p % MOD)) % MOD) % MOD;
    }
    sort(events.begin(), events.end());
    
    vector<pair<long long, long long> > cards; // from, cnt
    OPT = (MOD - OPT) % MOD;
    for (int i = 0; i < 2 * m; ++i) {
        long long cur_stop = events[i].first;
        long long num_pas = events[i].second;
        if (num_pas > 0) {
            int y = (int)cards.size() - 1;
            while (num_pas > 0) {
                long long r = min(num_pas, cards[y].second);
                OPT = (OPT + (GetCost(cards[y].first, cur_stop) % MOD) * (r % MOD)) % MOD;
                num_pas -= r;
                cards[y].second -= r;
                --y;
            }
        } else { // Entering
            cards.push_back(make_pair(cur_stop, -num_pas));
        }
    }
    cerr << case_num << endl;
    cout << "Case #" << case_num << ": " << (MOD - OPT) % MOD << endl;

}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve(i + 1);
}

