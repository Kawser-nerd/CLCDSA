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
typedef priority_queue<lint> p_que;
typedef priority_queue<lint, vector<lint>, greater<lint>()> p_que_rev;
const lint INF = INT_MAX;
const lint LINF = LLONG_MAX;
const lint MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const lint di[]{0, -1, 0, 1, -1, -1, 1, 1};
const lint dj[]{1, 0, -1, 0, 1, -1, -1, 1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b;
    string s;
    cin >> a >> b;
    cin >> s;
    string ans = "Yes";
    for (int i=0; i<a; ++i){
        if(!(0 <= s[i] - '0' && s[i] - '0' <= 9)){
            ans = "No";
            break;
        }
    }
    for (int i=a+1; i<a+b+1; ++i){
        if(!(0 <= s[i] - '0' && s[i] - '0' <= 9)){
            ans = "No";
            break;
        }
    }
    if(s[a] != '-'){
        ans = "No";
    }
    cout << ans << "\n";
    return 0;
}