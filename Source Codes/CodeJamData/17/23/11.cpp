#include <bits/stdc++.h>

using namespace std;

int n;
long long dist[128][128];
long double dist2[128][128];
#define INF 1000000000000000LL
vector<pair<long long, long double> > horses;

void solve() {
    int q;
    cin >> n >> q;
    horses.resize(n);
    for(int i=0;i<n;i++) {
        cin >> horses[i].first >> horses[i].second;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            long long a;
            cin >> a;
            if(a == -1) {
                if(i == j) {
                    a = 0;
                } else {
                    a = INF;
                }
            }
            dist[i][j] = a;
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist2[i][j] = 1e12;
            if(dist[i][j] <= horses[i].first) {
                dist2[i][j] = (long double)dist[i][j]/horses[i].second;
            }
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist2[i][j] = min(dist2[i][j],dist2[i][k]+dist2[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++) {
        int a,b;
        cin >> a >> b;
        printf(" %6f",(double)dist2[a-1][b-1]);
    }
    cout << endl;
}

int main () {
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++ ){
        printf("Case #%d:",casito);
        solve();
    }
}