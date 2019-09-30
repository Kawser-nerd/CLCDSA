#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

int win(vector<int>& h, int hand){
    switch(hand){
        case 1:
            return h[2];
        case 2:
            return h[3];
        case 3:
            return h[1];
        default:
            break;
    }
    return 0;
}

signed main(){
    int n;
    cin >> n;

    vector<P> p(n), q(n);
    for(int i = 0; i < n; i++){
        int r, h;
        cin >> r >> h;
        p[i] = make_pair(r, h);
        q[i] = make_pair(r, h);
    }
    sort(q.begin(), q.end());

    for(int i = 0; i < n; i++){
        int l = -1;
        int r = n;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(p[i].first > q[m].first){
                l = m;
            }else{
                r = m;
            }
        }
        int lt = l;

        l = -1;
        r = n;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(p[i].first >= q[m].first){
                l = m;
            }else{
                r = m;
            }
        }
        int eq = l;

        vector<int> h(4);
        l = lt;
        r = eq+1;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(1 >= q[m].second){
                l = m;
            }else{
                r = m;
            }
        }
        h[1] = l - lt;

        l = lt;
        r = eq+1;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(2 >= q[m].second){
                l = m;
            }else{
                r = m;
            }
        }
        h[2] = l - (lt + h[1]);
        h[3] = eq - (lt + h[1] + h[2]);

        lt += win(h, p[i].second) + 1;
        eq = h[p[i].second] - 1;
        int gt = n - (lt + eq + 1);

        cout << lt << " " << gt << " " << eq << endl;
    }

    return 0;
}