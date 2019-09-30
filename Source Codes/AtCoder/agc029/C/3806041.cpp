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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

void connect(vector<P>& dat){
    if(dat.size() <= 1){
        return;
    }

    if(dat[SZ(dat)-1].first == dat[SZ(dat)-2].first){
        dat[SZ(dat)-2].second += dat[SZ(dat)-1].second;
        dat.pop_back();
    }
}

void carry(vector<P>& dat, int k){
    if(dat.back().first < k){
        return;
    }
    dat.pop_back();

    if(dat.size() == 0){
        return;
    }

    if(dat.back().first != k - 1){
        if(dat.back().second == 1){
            dat.back().first++;
            dat.emplace_back(0, 1);
            return;
        }
        dat.back().second--;
        dat.emplace_back(dat.back().first + 1, 1);
        dat.emplace_back(0, 1);
        return;
    }

    P last = dat.back();
    dat.pop_back();

    if(dat.size() == 0){
        return;
    }
    if(dat.back().second == 1){
        dat.back().first++;
        dat.emplace_back(0, last.second + 1);
        return;
    }
    dat.back().second--;
    dat.emplace_back(dat.back().first + 1, 1);
    dat.emplace_back(0, last.second + 1);
}

void increment(vector<P>& dat){
    if(dat.back().second == 1){
        dat.back().first++;
        return;
    }
    dat.back().second--;
    dat.emplace_back(dat.back().first + 1, 1);
}

bool judge(const vector<int>& a, int k){
    vector<P> dat;
    int pos = 0;

    rep(i, SZ(a)){
        if(pos < a[i]){
            dat.emplace_back(0, a[i] - pos);
            pos = a[i];
            continue;
        }

        while(pos > a[i]){
            P last = dat.back();
            dat.pop_back();
            pos -= last.second;
            if(pos < a[i]){
                dat.emplace_back(last.first, a[i] - pos);
                pos = a[i];
            }
        }
        increment(dat);
        carry(dat, k);

        if(dat.size() == 0){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int lo = 0;
    int hi = n;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(judge(a, mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    cout << hi << endl;

    return 0;
}