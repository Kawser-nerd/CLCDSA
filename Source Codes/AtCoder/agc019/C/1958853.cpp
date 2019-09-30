#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;
using P = pair<int, int>;

const int INF = 200000000;
const int NMAX = 200002;

P S, G;
int N;
vector<P> f;
int dp[NMAX];

int main(){
    cin >> S.first >> S.second >> G.first >> G.second;
    int xmin = min(S.first, G.first);
    int xmax = max(S.first, G.first);
    int ymin = min(S.second, G.second);
    int ymax = max(S.second, G.second);

    if (S.first != xmin) {
        P temp = S;
        S = G;
        G = temp;
    }
    //cout << S.first << ", " << S.second << " " << G.first << ", " << G.second << endl;

    cin >> N;
    bool rev = S.second >= G.second;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        if (x >= xmin && x <= xmax && y >= ymin && y <= ymax) {
            if (rev) y = ymax - y; else y = y - ymin;
            f.push_back(P(x, y));
            //cout << x << ',' << y << endl;
        }
    }
    
    double ans = (xmax - xmin + ymax - ymin) * 100.;

    if (ymin == ymax || xmin == xmax) {
        ans += f.size() * (10 * M_PI - 20);
    } else {
        sort(f.begin(), f.end());

        for (int i = 0; i < NMAX; ++i) {
            dp[i] = INF;
        }

        for (P fi : f) {
            int y = fi.second;
            //cout << y << endl;
            *lower_bound(dp, dp + NMAX, y) = y;
        }
        int fs = lower_bound(dp, dp + NMAX, INF) - dp;
        if (fs < min(xmax - xmin, ymax - ymin) + 1) {
            ans -= fs * (20 - 5 * M_PI);
        } else {
            //cout << "ss" << endl;
            ans += - (fs - 1) * (20 - 5 * M_PI) + (10 * M_PI - 20);
        }
    }
    printf("%.18lf\n", ans);
}