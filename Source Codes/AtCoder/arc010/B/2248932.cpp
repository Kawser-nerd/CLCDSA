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

    vector<bool> d(367, false);
    for(int i = 1; i < 367; i++){
        if(i % 7 == 0 || i % 7 == 1){
            d[i] = true;
        }
    }

    vector<int> dd(n);
    rep(i, n){
        signed month, day;
        scanf("%d/%d", &month, &day);
        int m = 1;
        while(m < month){
            if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
                day += 31;
            }else if(m == 2){
                day += 29;
            }else{
                day += 30;
            }
            m++;
        }
        dd[i] = day;
    }
    sort(dd.begin(), dd.end());

    rep(i, n){
        while(d[dd[i]] && dd[i] < 366){
            dd[i]++;
        }
        d[dd[i]] = true;
    }

    int ans = 0;
    int tmp = 0;
    for(int i = 1; i < 367; i++){
        if(d[i]){
            tmp++;
            continue;
        }
        if(tmp > ans){
            ans = tmp;
        }
        tmp = 0;
    }
    if(tmp > ans){
        ans = tmp;
    }
    cout << ans << endl;

    return 0;
}