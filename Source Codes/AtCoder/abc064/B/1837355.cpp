#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::min_element;
using std::max_element;
using std::sort;
using std::abs;

int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end());

    cout << r - l << endl;

    return 0;
}