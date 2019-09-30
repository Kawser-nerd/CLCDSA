#include <string.h>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <functional>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define sz(a)  int((a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define CLR(a) memset((a), 0, sizeof(a))
#define INF (1 << 31) - 1
const int dh[8] = {-1, 1, 0, 0,1,1,-1,-1};
const int dw[8] = {0, 0, 1, -1,1,-1,1,-1};
typedef long long ll;
typedef pair<int, int> p;
typedef vector <int> VI;
typedef vector <string> VS;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;
map<lli, lli> d;
set<lli> s;

int main(){
/*	
	int n;
	cin >> n;
	VI a(n+1);

	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		a[num] = i;
	}
	
	ll ans = 0;
	vector <int> his;
	his.pb(0);
	his.pb(n+1);

	for(int i = 1; i <= n; i++){
		his.pb(a[i]);
		sort( all(his) );
		vector<int>::iterator it = lower_bound( all(his), a[i] );
		int h = a[i] - *(it - 1);
		int w = *(it + 1) - a[i];	
						
		ans += h * w * i;
	}

	cout << ans << endl;
*/
 lli n;
    lli a[200005] = {};
    cin >> n;
    s.insert(-1);
    s.insert(n);
    lli ans = 0;
    rep(i, n)
    {
        cin >> a[i];
        d[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        s.insert(d[i]);
        auto it = s.find(d[i]);
        --it;
        lli left = *it;
        ++it;
        ++it;
        lli right = *it;
        ans += i * (d[i] - left) * (right - d[i]);
        //cout << ans << endl;
    }
    cout << ans << endl;
	return 0;	
}