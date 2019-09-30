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
    int n;
    cin >> n;

    int da = -1;
    int a = -1;
    for(int i = 2; i <= n; i++){
        cout << "? " << 1 << " " << i << endl;

        int d;
        cin >> d;
        if(d > da){
            a = i;
            da = d;
        }
    }

    int ans = -1;
    for(int i = 1; i <= n; i++){
        if(a == i){
            continue;
        }
        cout << "? " << a << " " << i << endl;

        int d;
        cin >> d;
        if(d > ans){
            ans = d;
        }
    }

    cout << "! " << ans << endl;

    return 0;
}