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
    int w, h, n;
    cin >> w >> h >> n;

    vector<vector<int>> b(h, vector<int>(w));

    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if ((a == 1 && k < x) || (a == 2 && k >= x) ||
                    (a == 3 && j < y) || (a == 4 && j >= y)) {
                    b[j][k] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for (int j = 0; j < h; j++) {
        for (int k = 0; k < w; k++) {
            if(b[j][k] == 0){
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}