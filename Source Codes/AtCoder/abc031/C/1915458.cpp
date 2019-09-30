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
const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = -INF;
    for (int i = 0; i < n; i++) {
        int opt_odd_sum = -INF;
        int opt_evn_sum = -INF;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int s = min(i, j);
            int t = max(i, j);

            int odd_sum = 0;
            int evn_sum = 0;
            for(int k = s; k <= t; k++){
                if((k - s) % 2 == 0){
                    evn_sum += a[k];
                }else{
                    odd_sum += a[k];
                }
            }

            if(odd_sum > opt_odd_sum){
                opt_odd_sum = odd_sum;
                opt_evn_sum = evn_sum;
            }
        }
        ans = max(ans, opt_evn_sum);
    }

    cout << ans << endl;

    return 0;
}