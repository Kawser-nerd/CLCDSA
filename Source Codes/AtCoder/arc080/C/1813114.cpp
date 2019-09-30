#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }





typedef int VAL;
const VAL INF = 1<<29;
const int MAX_R = 510000;

int SIZE_R;
struct RMQ {
    pair<VAL,int> dat[4*MAX_R];
    
    void init(int n = MAX_R, VAL v = INF) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        for (int i = 0; i < 2*MAX_R-1; ++i) dat[i] = make_pair(v, -1);
    }
    
    inline void init_set(int a, VAL x) {
        int k = a + SIZE_R-1;
        dat[k] = make_pair(x, a);
    }
    
    inline void init_tree(int k = 0, int l = 0, int r = SIZE_R) {
        if (r - l == 1) {}                  // leaf
        else {
            init_tree(k*2+1, l, (l+r)/2);
            init_tree(k*2+2, (l+r)/2, r);
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    
    inline void set(int a, VAL x) {
        int k = a + SIZE_R-1;
        dat[k] = make_pair(x, a);
        while (k > 0) {
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    
    inline pair<VAL,int> get(int a, int b, int k = 0, int l = 0, int r = SIZE_R) {
        if (r <= a || b <= l) return make_pair(INF, -1);
        if (a <= l && r <= b) return dat[k];
        else {
            pair<VAL,int> vl = get(a, b, k*2+1, l, (l+r)/2);
            pair<VAL,int> vr = get(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
    
    inline pair<VAL,int> operator [] (int a) {
        return get(a, a+1);
    }
    
    void print(int r = SIZE_R) {
        for (int i = 0; i < SIZE_R; ++i) {cout << get(i, i+1) << ",";}
        cout << endl;
    }
};

RMQ rmq[2];



int N;
int p[510000];

typedef pair<int,int> pint;

vector<pint> alt;
map<pint,int> inv;
vector<int> graph[510000];


void solve(int left, int right, int par) {
    if (left >= right) return;

    pair<VAL,int> pa = rmq[left%2].get(left, right - 1);
    pair<VAL,int> pb = rmq[(left+1)%2].get(pa.second + 1, right);
    pair<int,int> add = make_pair(pa.first, pb.first);
    int cur = (int)alt.size();
    alt.push_back(add);
    inv[add] = cur;
    if (par != -1) graph[par].push_back(cur);
    solve(pa.second + 1, pb.second, cur);
    solve(left, pa.second, cur);
    solve(pb.second + 1, right, cur);
}


int main() {
    while (cin >> N) {
        for (int i = 0; i < N; ++i) scanf("%d", &p[i]);
        
        rmq[0].init(N+1);
        rmq[1].init(N+1);
        
        for (int i = 0; i < N; ++i) {
            rmq[i%2].init_set(i, p[i]);
        }
        rmq[0].init_tree();
        rmq[1].init_tree();
        
        alt.clear();
        inv.clear();
        for (int i = 0; i < 510000; ++i) graph[i].clear();
        solve(0, N, -1);

        priority_queue<pint, vector<pint>, greater<pint> > que;
        que.push(alt[0]);
        
        vector<pint> res;
        while (!que.empty()) {
            pint cur = que.top();
            que.pop();
            res.push_back(cur);
            int cur_ind = inv[cur];
            for (int i = 0; i < graph[cur_ind].size(); ++i) {
                int next_ind = graph[cur_ind][i];
                que.push(alt[next_ind]);
            }
        }
        
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].first << " " << res[i].second;
            if (i != res.size() - 1) cout << " ";
        }
        cout << endl;
    }
}