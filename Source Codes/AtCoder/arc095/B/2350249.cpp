#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    double half = a[n-1] / 2.0;

    int left = 0;
    int right = n-1;
    while(right - left > 1){
        int mid = left + (right - left) / 2;
        if(a[mid] <= half){
            left = mid;
        }else{
            right = mid;
        }
    }
    int lh = left;

    left = 0;
    right = n-2;
    while(right - left > 1){
        int mid = left + (right - left) / 2;
        if(a[mid] >= half){
            right = mid;
        }else{
            left = mid;
        }
    }
    int rh = right;

    if(half - a[lh] < a[rh] - half){
        cout << a[n-1] << " " << a[lh] << endl;
    }else{
        cout << a[n-1] << " " << a[rh] << endl;
    }

    return 0;
}