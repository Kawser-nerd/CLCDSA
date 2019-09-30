#include <algorithm>
#include <complex>
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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    int cnt;
    for (int i = 0; i < n; i += cnt) {
        cnt = 0;
        for (int j = i; j < n && a[i] == a[j]; j++) {
            cnt++;
        }

        if(a[i] == cnt){
            continue;
        }

        if(cnt > a[i]){
            ans += cnt - a[i];
        }else{
            ans += cnt;
        }
    }

    cout << ans << endl;

    return 0;
}