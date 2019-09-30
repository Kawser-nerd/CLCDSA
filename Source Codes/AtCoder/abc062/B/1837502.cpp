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
using std::sort;
using std::abs;

int main(void) {
    int h, w;
    cin >> h >> w;

    for (int i = 0; i < w + 2; i++) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        cout << "#" << s << "#" << endl;
    }
    for (int i = 0; i < w + 2; i++) {
        cout << "#";
    }
    cout << endl;
    return 0;
}