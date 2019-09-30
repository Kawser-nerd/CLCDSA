#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

void solve(string s, long long x, long long y){
    pair<long long, long long> dest(x, y);
    pair<long long, long long> orig(0, 0);
    vector< vector<long long> > xy(2, vector<long long>());
    long long tmp = 0;
    int c = 0;
    int i_ = 0;
    while (s[i_] != 'T' && i_ < s.size()) {
        i_++;
    }
    orig.first += i_;
    for (int i = i_; i < s.size(); i++) {
        if (s[i] == 'T') {
            if (tmp != 0) {
                xy[c].push_back(tmp);
            }
            c = c==0 ? 1 : 0;
            tmp = 0;
        } else {
            tmp++;
        }
    }
    if (tmp != 0) {
        xy[c].push_back(tmp);
    }
    long long xmax = accumulate(xy[0].begin(), xy[0].end(), 0);
    long long ymax = accumulate(xy[1].begin(), xy[1].end(), 0);
    vector< vector<bool> > dpx(2, vector<bool>((xmax)*2+1+orig.first, false));
    int e = 0;
    dpx[e][xmax+orig.first] = true;
    for (int i = 0; i < xy[0].size(); i++) {
        dpx[e==0 ? 1 : 0].assign((xmax)*2+1+orig.first, false);
        for (int j = 0; j < (xmax*2)+1+orig.first; j++) {
            if (dpx[e][j]) {
                dpx[e==0 ? 1 : 0][j+xy[0][i]] = true;
                dpx[e==0 ? 1 : 0][j-xy[0][i]] = true;
            }
        }
        e = e==0 ? 1 : 0;
    }
    vector< vector<bool> > dpy(2, vector<bool>((ymax)*2+1, false));
    int e2 = 0;
    dpy[e2][ymax+orig.second] = true;
    for (int i = 0; i < xy[1].size(); i++) {
        dpy[e2==0 ? 1 : 0].assign((ymax)*2+1, false);
        for (int j = 0; j < (ymax*2)+1; j++) {
            if (dpy[e2][j]) {
                dpy[e2==0 ? 1 : 0][j+xy[1][i]] = true;
                dpy[e2==0 ? 1 : 0][j-xy[1][i]] = true;
            }
        }
        e2 = e2==0 ? 1 : 0;
    }
    if (dest.first > xmax+orig.first || dest.first < -xmax+orig.first || dest.second > ymax || dest.second < -ymax) {
        std::cout << "No" << std::endl;
    } else {
        if (dpx[e][xmax+dest.first] && dpy[e2][ymax+dest.second]) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long x;
    string s;
    long long y;
    cin >> s;
    scanf("%lld",&x);
    scanf("%lld",&y);
    solve(s, x, y);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}