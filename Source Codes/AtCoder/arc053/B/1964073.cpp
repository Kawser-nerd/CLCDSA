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
    string s;
    cin >> s;

    vector<int> a('z' + 1);
    for (char i : s) {
        a[i]++;
    }

    int n = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (a[i] % 2 != 0) {
            n++;
        }
    }


    int l = s.length();
    int pair_cnt = (l - n) / 2;
    if(n == 0){
        cout << l << endl;
    }else{
        cout << 1 + (pair_cnt / n) * 2 << endl;
    }

    return 0;
}