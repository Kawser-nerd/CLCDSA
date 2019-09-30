#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000
#define M 1000000007
using namespace std;

int n;
vector<int> g[MAX_N];
unsigned long long dpb[MAX_N], dpw[MAX_N];
bool used[MAX_N];

unsigned long long solve_w(int);

unsigned long long solve_b(int from)
{
    if (dpb[from] > 0) {
        return dpb[from];
    }
    unsigned long long ret = 1;
    used[from] = true;
    for (int j = 0; j < g[from].size(); j++) {
        int to = g[from][j];
        if (!used[to]) {
            ret = (ret * solve_w(to)) % M;
        }
    }
    used[from] = false;
    return dpb[from] = ret;
}

unsigned long long solve_w(int from)
{
    if (dpw[from] > 0) {
        return dpw[from];
    }
    unsigned long long ret = 1;
    used[from] = true;
    for (int j = 0; j < g[from].size(); j++) {
        int to = g[from][j];
        if (!used[to]) {
            ret = (ret * (solve_w(to) + solve_b(to))) % M;
        }
    }
    used[from] = false;
    return dpw[from] = ret;
}

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(used, used + n, false);
    cout << (solve_b(0) + solve_w(0)) % M << endl;
    return 0;
}