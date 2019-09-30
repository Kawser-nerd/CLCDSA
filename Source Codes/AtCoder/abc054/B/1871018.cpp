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

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            bool match = true;
            for(int x = 0; x < m; x++){
                for(int y = 0; y < m; y++){
                    if(a[i+x][j+y] != b[x][y]){
                        match = false;
                        goto out;
                    }
                }
            }
            out:
            if(match){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}