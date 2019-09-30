/*
???  ??????
?? ?´????)?????/???????????????????
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

string ret_dir(int n){
    string dir;
    switch(n){
        case 0:
            dir = "N";
            break;
        case 1:
            dir = "NNE";
            break;
        case 2:
            dir = "NE";
            break;
        case 3:
            dir = "ENE";
            break;
        case 4:
            dir = "E";
            break;
        case 5:
            dir = "ESE";
            break;
        case 6:
            dir = "SE";
            break;
        case 7:
            dir = "SSE";
            break;
        case 8:
            dir = "S";
            break;
        case 9:
            dir = "SSW";
            break;
        case 10:
            dir = "SW";
            break;
        case 11:
            dir = "WSW";
            break;
        case 12:
            dir = "W";
            break;
        case 13:
            dir = "WNW";
            break;
        case 14:
            dir = "NW";
            break;
        case 15:
            dir = "NNW";
            break;
    }
    return dir;
}

int wind(int w){
    int ret;
    double w_r = w / 60.0;
    const double eps = 1.0 / 60.0 - EPS;
    const double diff = 0.05 + eps;
    //printf("%.16f\n", w_r);
    if(w_r >= 32.7 - diff){
        ret = 12;
    }
    else if(w_r >= 28.5 - diff){
        ret = 11;
    }
    else if(w_r >= 24.5 - diff){
        ret = 10;
    }
    else if(w_r >= 20.8 - diff){
        ret = 9;
    }
    else if(w_r >= 17.2 - diff){
        ret = 8;
    }
    else if(w_r >= 13.9 - diff){
        ret = 7;
    }
    else if(w_r >= 10.8 - diff){
        ret = 6;
    }
    else if(w_r >= 8.0 - diff){
        ret = 5;
    }
    else if(w_r >= 5.5 - diff){
        ret = 4;
    }
    else if(w_r >= 3.4 - diff){
        ret = 3;
    }
    else if(w_r >= 1.6 - diff){
        ret = 2;
    }
    else if(w_r >= 0.3 - diff){
        ret = 1;
    }
    else {
        ret = 0;
    }
    return ret;
}

pair<string, int> dir(int deg, int dis){
    pair<string, int> ret;
    double deg_n = deg / 10.0;
    const double diff = 22.50;
    double l = 11.25;
    double r = 11.25 + diff;
    ret.snd = wind(dis);
    if(ret.snd == 0){
        ret.fst = "C";
    }
    else {
        for (int i=1; i<=16; ++i){
            if(i != 16 && l <= deg_n && deg_n < r){
                ret.fst = ret_dir(i);
                break;
            }
            if(i == 16){
                ret.fst = ret_dir(0);
                break;
            }
            l = 11.25 + diff * i;
            r = 11.25 + diff * (i + 1);
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int deg, dis;
    cin >> deg >> dis;
    pair<string, int> ans = dir(deg, dis);
    cout << ans.fst << " " << ans.snd << "\n";
    return 0;
}