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

string fst, lst;

bool movable(string src, string dst){
    int n = 0;

    rep(i, (int)src.size()){
        if(src[i] != dst[i]){
            n++;
        }
    }

    return n == 1;
}

void solve(set<string>& s, string first){
    queue<string> q;
    q.push(first);
    map<string, string> m;

    while(not q.empty()){
        string now = q.front();
        q.pop();

        auto begin = s.begin();
        auto end = s.end();
        for(auto it = begin; it != end;){
            if(not movable(*it, now)){
                it++;
                continue;
            }

            q.push(*it);
            m[*it] = now;
            it = s.erase(it);
        }
    }

    if(m.find(lst) == m.end()){
        cout << -1 << endl;
        return;
    }

    vector<string> r;
    string now = lst;
    r.push_back(now);
    while(now != fst){
        now = (m.find(now))->second;
        r.push_back(now);
    }

    cout << r.size() - 2 << endl;
    for(int i = (int)r.size() - 1; i >= 0; i--){
        cout << r[i] << endl;
    }
}

signed main(){
    int n;
    cin >> fst >> lst >> n;

    set<string> s;
    rep(i, n){
        string ss;
        cin >> ss;
        s.insert(ss);
    }
    s.insert(lst);

    if(fst == lst){
        cout << 0 << endl;
        cout << fst << endl;
        cout << lst << endl;
        return 0;
    }

    solve(s, fst);

    return 0;
}