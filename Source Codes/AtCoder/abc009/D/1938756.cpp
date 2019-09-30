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
const int INF = 1e9 + 314;

typedef vector<vector<uint>> mat;
typedef unsigned int uint;

std::ostream& operator<<(std::ostream& os, vector<uint>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << setw(8) << std::setbase(16) << v[i] << " ";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, vector<vector<uint>>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << "| " << v[i] << " |" << endl;
    }
    return os;
}

vector<vector<uint>> mul(int n, const mat& a, const mat& b) {
    mat c(n, vector<uint>(n));
    for (int i = 0; i < n; i++) {      // i-row
        for (int j = 0; j < n; j++) {  // j-col
            uint w = 0;
            for (int k = 0; k < n; k++) {
                w ^= a[i][k] & b[k][j];
            }
            c[i][j] = w;
        }
    }
    return c;
}

int main() {
    int k, m;
    cin >> k >> m;

    vector<uint> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    if (m <= k) {
        cout << a[m - 1] << endl;
        return 0;
    }

    mat b(k, vector<uint>(k));
    for (int i = 0; i < k - 1; i++) {
        b[i][i + 1] = 0xFFFFFFFF;
    }
    for (int i = 0; i < k; i++) {
        cin >> b[k - 1][k - 1 - i];
    }

    vector<mat> bb(32, mat(k, vector<uint>(k)));
    bb[0] = b;
    for (int i = 1; i < 32; i++) {
        bb[i] = mul(k, bb[i - 1], bb[i - 1]);
    }

    mat c(k, vector<uint>(k));
    for (int i = 0; i < k; i++) {
        c[i][i] = 0xFFFFFFFF;
    }
    for (int i = 0; i < 32; i++) {
        if ((m - k) & (1 << i)) {
            c = mul(k, bb[i], c);
        }
    }

    uint ans = 0;
    for (int i = 0; i < k; i++) {
        ans ^= c[k - 1][i] & a[i];
    }
    cout << ans << endl;

    return 0;
}