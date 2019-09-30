#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <utility>

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
using std::map;
using std::pair;
using std::make_pair;

typedef long long int ll;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());

    map<int, int> c;
    int ind = 0;
    c.insert(make_pair(sorted_a[0], ind++));
    for (int i = 1; i < n; i++) {
        if(sorted_a[i] == sorted_a[i-1]){
            continue;
        }
        c.insert(make_pair(sorted_a[i], ind++));
    }

    for(int i = 0; i < n; i++){
        cout << c[a[i]] << endl;
    }

    return 0;
}