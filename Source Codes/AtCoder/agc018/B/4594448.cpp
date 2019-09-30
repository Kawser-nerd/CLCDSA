/*
???  ??????
?? ?�????)?????/???????????????????
?? ??y:::::???? [?]??????????????????????????????????
?? |:?:|:::::|???|??|
?????????????????|?????????????????
???????????????|??  ??????????????????????????????
???????????????|
???????????????.?|????????????????????????????????
????????????? ??  |??????????????????????????
??????????|???  |?????????????????????????????????
?????????????? |????????????????????
???(??)?(??)?(??)??|
?    ||?? ||??||??|??? ????????????
??.?|???|? ?|?
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define fst first
#define snd second
#define ALL(obj) (obj).begin(),(obj).end()
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

int solve(int n, int m, vector<vector<int>> &a){
    vector<int> sports(m, 0);
    int count[m];
    int min_ans = INF;
    int max_num;
    int max_itr;
    for(int loop = 0; loop < m; ++loop){
        for (int i=0; i<m; ++i){
            count[i] = 0;
        }
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                if(sports[a[i][j]] == 0){
                    count[a[i][j]]++;
                    break;
                }
            }
        }
        max_num = -1;
        max_itr = -1;
        for (int i=0; i<m; ++i){
            if(max_num < count[i]){
                max_num = count[i];
                max_itr = i;
            }
        }
        min_ans = min(min_ans, max_num);
        sports[max_itr] = 1;
        debugpair(min_ans, max_itr+1);
    }
    return min_ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i=0; i<n; ++i){
        a[i].resize(m);
        for (int j=0; j<m; ++j){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = solve(n, m, a);
    cout << ans << endl;
    return 0;
}