#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

double p[25], s[25], y;
double b[1<<25];
int n;

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        scanf("%lf %d", &y, &n);
        FO(i,0,n) scanf("%lf", p+i);
        FO(i,0,n) scanf("%lf", s+i);
        FO(i,0,1<<n) b[i] = 1e15;
        b[0] = 0;
        double res = 1e15;
        FO(i,0,1<<n) if (b[i] < 1e14) {
            // got all of i and returned to centre
            double t = b[i];
            vector<pair<double,int> > l, r;
            FO(j,0,n) {
                if (p[j] > 0) {
                    double cp = p[j]+t*s[j];
                    r.emplace_back(cp / (y-s[j]), j);
                } else {
                    double cp = -p[j]+t*s[j];
                    l.emplace_back(cp / (y-s[j]), j);
                }
            }
            sort(l.begin(),l.end());
            sort(r.begin(),r.end());
            // go left
            int nm = i;
            FO(j,0,sz(l)) {
                nm |= 1<<l[j].second;
                if (nm == (1<<n)-1) res = min(res, t + l[j].first);
                b[nm] = min(b[nm], t + 2*l[j].first);
            }
            // go right
            nm = i;
            FO(j,0,sz(r)) {
                nm |= 1<<r[j].second;
                if (nm == (1<<n)-1) res = min(res, t + r[j].first);
                b[nm] = min(b[nm], t + 2*r[j].first);
            }
        }
        printf("Case #%d: %.10lf\n", Z, res);
        fprintf(stderr, "DONE %d\n", Z);
    }
}

