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

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> r(n);
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }

    sort(r.begin(), r.end());

    double takahashi = 0;
    for(int i = n - k; i < n; i++){
        takahashi = (takahashi + r[i]) / 2;
    }

    cout << fixed << setprecision(16) << takahashi << endl;

    return 0;
}