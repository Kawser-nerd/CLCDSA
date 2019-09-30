#include <cstdio>
using namespace std;
#include <vector>
#include <iostream>

vector<vector<int> > sm;
vector<int> num_inbound;
vector<bool> used;

void AddEdge(int from, int t) {
    sm[from].push_back(t);
    ++num_inbound[t];
//    cerr << "a[" << from + 1 << "] < a[" << t + 1 << "]" << endl;
}

void solve(int case_num) {
    int n;
    cin >> n;
    sm.resize(n);
    num_inbound.resize(n);
    used.resize(n);
    for (int i = 0; i < n; ++i) {
        sm[i].clear();
        num_inbound[i] = 0;
        used[i] = false;
    }
    cerr << case_num << endl;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int lst = -1;
        for (int j = 0; j < i; ++j) {
            if (a[i] <= a[j]) AddEdge(i, j);
            if (a[i] == a[j] + 1) lst = j;
        }
        if (lst != -1) AddEdge(lst, i);
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cerr << case_num << endl;
    for (int i = n - 1; i >= 0; --i) {
        int lst = -1;
        for (int j = n - 1; j > i; --j) {
            if (b[j] >= b[i]) AddEdge(i, j);
            if (b[i] == b[j] + 1) lst = j;
        }
        if (lst != -1) AddEdge(lst, i);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int x = -1;
        for (int j = 0; j < n; ++j) if (!used[j] && num_inbound[j] == 0) {
            x = j;
            break;
        }
        ans[x] = i + 1;
        used[x] = true;
        for (int j = 0; j < (int)sm[x].size(); ++j)
            --num_inbound[sm[x][j]];
    }
    cout << "Case #" << case_num << ":";
    for (int i = 0; i < n; ++i) cout << " " << ans[i];
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve(i + 1);
    return 0;
}
