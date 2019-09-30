#include <iostream>

using namespace std;
long a[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    long cnt = 0, sum = 0;
    // case 1: pos, neg, pos, ...
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (i % 2 == 0 & sum <= 0) {
            cnt += 1 - sum;
            sum = 1;
        } else if (i % 2 == 1 & sum >= 0) {
            cnt += sum + 1;
            sum = -1;
        }
        //cout << cnt << " ";
    }
    //cout << endl;
    long cnt_even = cnt;
    sum = cnt = 0;
    // case 2: neg, pos, neg, ...
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (i % 2 == 1 & sum <= 0) {
            cnt += 1 - sum;
            sum = 1;
        } else if (i % 2 == 0 & sum >= 0) {
            cnt += sum + 1;
            sum = -1;
        }
        //cout << cnt << " ";
    }
    //cout << endl;
    
    cout << min(cnt, cnt_even) << endl;
    
    return 0;
}