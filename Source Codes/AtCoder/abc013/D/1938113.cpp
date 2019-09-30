#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;
using std::swap;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

vector<int> combine(int n, const vector<int>& p, const vector<int>& q) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = q[p[i]];
    }
    return ans;
}

template <class T>
std::ostream& operator<<(std::ostream& os, vector<T> v){
    os << "[ ";
    for(T e : v){
        os << e << ", ";
    }
    os << " ]";
    return os;
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = m - 1; i >= 0; i--) {
        swap(p[a[i]], p[a[i] + 1]);
    }

    vector<vector<int>> pp(31, vector<int>(n));
    pp[0] = p;
    for (int i = 1; i <= 30; i++) {
        pp[i] = combine(n, pp[i - 1], pp[i - 1]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i;
    }

    for (int i = 0; i <= 30; i++) {
        if (d & (1 << i)) {
            ans = combine(n, ans, pp[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}