#include <cstdio>
#include <deque>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
using namespace std;

int main() {
    int n, l; scanf("%d%d", &n, &l);
    vector<int> t(n), v(n); repeat (i, n) scanf("%d%d", &t[i], &v[i]);
    deque<pair<int, double> > deq;
    deq.emplace_back(v[0], t[0]);
    double acc = t[0] *(double) v[0];
    printf("%.12lf\n", acc /(double) l);
    repeat_from (i, 1, n) {
        for (int nv = v[i]; nv > 0; ) {
            int dv = min(nv, deq.front().first);
            nv -= dv;
            deq.front().first -= dv;
            acc -= deq.front().second * dv;
            if (deq.front().first == 0) {
                deq.pop_front();
            }
        }
        int nv = v[i];
        double nt = t[i];
        while (not deq.empty() and deq.back().second > nt) {
            int pv; double pt; tie(pv, pt) = deq.back();
            deq.pop_back();
            nt = (nt * nv + pt * pv) / (nv + pv);
            nv += pv;
        }
        deq.emplace_back(nv, nt);
        acc += t[i] *(double) v[i];
        printf("%.12lf\n", acc /(double) l);
    }
    return 0;
}