#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#define debug(x) cout << #x << ": " << (x) << endl
#define INF 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;

bool isValidPoint(const P& p, int h, int w){
    return p.first > 0 && p.second > 0 &&
        p.first + 2 <= h && p.second + 2 <= w;
}

vector<ull> solve(ull h, ull w, const vector<P>& ps){
    vector<ull> res(10, 0);
    map<P, int> squares;

    for(P p : ps){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int a = p.first;
                int b = p.second;
                P q = make_pair(a - i, b - j);
                if(isValidPoint(q, h, w)){
                    squares[q]++;
                }
            }
        }
    }

    for(auto kv : squares){
        res[kv.second]++;
        // cout << kv.first.first << ", " << kv.first.second << ": " << kv.second << endl;
    }
    ull s = 0;
    for(int i = 1; i < 10; i++){
        s += res[i];
    }
    res[0] = (h - 2) * (w - 2) - s;

    return res;
}

int main (int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ull h, w, n;
    cin >> h >> w >> n;
    vector<P> ps(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ps[i] = make_pair(a, b);
    }

    const vector<ull>& res = solve(h, w, ps);
    for(auto j : res){
        cout << j << endl;
    }

    return 0;
}