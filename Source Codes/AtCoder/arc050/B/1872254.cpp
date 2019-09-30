#include <algorithm>
#include <cctype>
#include <algorithm>
#include <cctype>
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

typedef long long int ll;

ll eval(ll r, ll b, ll x, ll y, ll n) {
    r -= x * n;
    b -= n;
    if(r < 0 || b < 0){
        return -1;
    }
    return n + min(r, b / y);
}

int main(void) {
    ll r, b, x, y;
    cin >> r >> b >> x >> y;

    // [low, high]
    ll low = 0;
    ll high = min(r / x, b);
    while (high - low > 16) {
        ll lmid = (high - low) / 3 + low;
        ll hmid = high - (high - low) / 3 ;

        ll val_lmid = -eval(r, b, x, y, lmid);
        ll val_hmid = -eval(r, b, x, y, hmid);
        if(val_lmid > val_hmid){
            low = lmid;
        }else{
            high = hmid;
        }
    }

    ll ans = -1;
    for(ll i = low; i <= high; i++){
        ans = max(ans, eval(r, b, x, y, i));
    }

    cout << ans << endl;

    return 0;
}