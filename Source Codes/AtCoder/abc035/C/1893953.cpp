#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        // [l, r)
        a[l]++;
        a[r]--;
    }

    for(int i = 0; i < n; i++){
        a[i+1] += a[i];
        a[i] &= 1;
    }

    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << endl;

    return 0;
}