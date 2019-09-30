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
    int n, x;
    cin >> n >> x;

    if(n == 2 && x == 2){
        cout << "Yes\n1\n2\n3" << endl;
        return 0;
    }

    if(x == 1 || x == 2 * n - 1){
        cout << "No" << endl;
        return 0;
    }

    vector<int> a(2*n-1);
    if(x == 2){
        int m = (2*n-1)/2;
        a[m-1] = 2*n-1;
        a[m] = 1;
        a[m+1] = 2;
        a[m+2] = 2*n-2;

        int y = 3;
        for(int i = 0; i < 2*n-1; i++){
            if(m-1 <= i && i <= m+2){
                continue;
            }
            a[i] = y++;
        }
    }else{
        int m = (2*n-1)/2;
        a[m-1] = 1;
        a[m] = x;
        a[m+1] = x+1;
        a[m+2] = 2;

        int y = 3;
        for(int i = 0; i < 2*n-1; i++){
            if(m-1 <= i && i <= m+2){
                continue;
            }
            if(y == x){
                y += 2;
            }
            a[i] = y++;
        }
    }

    cout << "Yes" << endl;

    rep(i, 2*n-1){
        cout << a[i] << endl;
    }
    return 0;
}