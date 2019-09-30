// ??
// ??????????????????????
// ??????????????????
// ?????????????????????????????

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

vector<set<int>> edges;
vector<int> degrees;
vector<int> degree_ones;
vector<int> deleted;

void delete_v(int v, vector<int>& new_degree_ones) {
    for (auto v_nei: edges[v]) {
        edges[v_nei].erase(v);
        degrees[v_nei] -= 1;
        if (degrees[v_nei] == 1) {
            new_degree_ones.pb(v_nei);
        }
    }
    edges[v].clear();
    degrees[v] = 0;
    deleted[v] = 1;
}

int main(void)
{
    cin.sync_with_stdio(false);
    int N;
    cin >> N;

    edges.resize(N);
    degrees.resize(N);
    deleted.resize(N);

    REP(n,N-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        edges[a].insert(b);
        edges[b].insert(a);
        ++degrees[a];
        ++degrees[b];
    }

    REP(i, N) {
        if (degrees[i] == 1) {
            degree_ones.pb(i);
        }
    }
    
    while(SIZE(degree_ones) > 0) {
        vector<int> new_degree_ones;
        vector<int> dummy;
        for(auto i: degree_ones) {

            // ???????????1?????????????????????
            if (degrees[i] != 1) continue;

            auto j = *edges[i].begin();

            delete_v(i, dummy);

            // cout << "-----------" << endl;
            // cout << i << " is deleted." << endl;
            // REP(i, N) {
            //     cout << "degrees of " << i << ": " << degrees[i] << endl;
            // }

            delete_v(j, new_degree_ones);

            // cout << "-----------" << endl;
            // cout << j << " (pair of i) is deleted." << endl;
            // REP(i, N) {
            //     cout << "degrees of " << i << ": " << degrees[i] << endl;
            // }

            // cout << "now new_degree_ones size:" << SIZE(new_degree_ones) << endl;
            // for(auto v : new_degree_ones) cout << v << ",";
            // cout << endl;
        }

        degree_ones = new_degree_ones;
    }

    REP(i, N) {
        if (deleted[i] == 0) {
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    return 0;
}