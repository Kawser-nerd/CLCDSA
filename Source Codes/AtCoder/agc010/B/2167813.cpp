#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

int main() {
    int n, a;
    vector<int> as;
    long sum = 0;
    cin >> n;
    
    REP(i,n) {
        cin >> a;
        sum += a;
        as.push_back(a);
    }
    
    int k = int(sum * 2 / n / (n + 1));
    int tmp = as[n-1];
    for (int i = n - 1; i >= 1; i--) {
        as[i] -= as[i-1];
    }
    as[0] -= tmp;
    
    REP(i,n) as[i] -= k;
    bool flag = k > 0 && sum % k == 0;
    int flagcnt = 0;
    REP(i,n) {
        if (as[i] != 0) {
            if (as[i] > 0) {
                flag = false;
            }
            if (as[i] % n != 0) {
                flag = false;
            } else {
                flagcnt += (-1 * as[i] / n);
            }
        }
    }
    
    if (flag && flagcnt == k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}