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
    rep(i, n){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }

        if(b - a <= 1){
            cout << a * 2 - 2 << endl;
            continue;
        }

        int left = 1;
        int right = 1e9;
        while(right - left > 1){
            int mid = left + (right - left) / 2;
            if(mid * mid < a * b){
                left = mid;
            }else{
                right = mid;
            }
        }
        if(left * (left + 1) >= a * b){
            cout << left * 2 - 2 << endl;
            continue;
        }

        cout << left * 2 - 1 << endl;
    }

    return 0;
}