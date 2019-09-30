#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define fst first;
#define snd second;
#define ALL(obj) (obj).begin(), (obj).end();
#define debug(x) cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y) cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y << ") (line:" << __LINE__ << ")" << '\n';
typedef long long lint;
typedef priority_queue<int> p_que;
typedef priority_queue<int, vector<int>, greater<int>()> p_que_rev;
const int INF = INT_MAX;
const lint LINF = LLONG_MAX;
const int MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int di[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dj[]{1, 0, -1, 0, 1, -1, -1, 1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    lint n;
    cin >> n;
    vector<lint> a(n);
    set<int> nums;
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    int res = 0;
    int r = 0;
    for (int l=0; l<n; ++l){
        while(r < n && nums.find(a[r]) == nums.end()){
            nums.insert(a[r]);
            //debug(a[r]);
            ++r;
        }
        res = max(res, r - l);
        //debug(res);
        if(r == l){
            ++r;
        }
        else {
            nums.erase(a[l]);
            //debug(a[l]);
        }
    }
    cout << res << endl;
    return 0;
}