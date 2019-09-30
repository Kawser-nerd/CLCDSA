#include <algorithm>
#include <cctype>
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

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x2 - x1) + abs(y2 - y1);
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    vector<int> d(m);

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i] >> d[i];
    }

    for(int i = 0; i < n; i++){
        int ans = 0;
        int min_dis = manhattan(a[i], b[i], c[0], d[0]);
        for(int j = 1; j < m; j++){
            int v = manhattan(a[i], b[i], c[j], d[j]);
            if(v < min_dis){
                min_dis = v;
                ans = j;
            }
        }
        cout << (ans + 1) << endl;
    }

    return 0;
}