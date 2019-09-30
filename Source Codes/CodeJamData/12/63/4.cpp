#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 1024;
const llint INF = 1000000007LL * 1000000007LL;

llint x[MAXN], y[MAXN], z[MAXN];
vector<llint> ss, dd;

void upd(pair<llint, llint>& ans, pair<llint, llint> tmp) {
    // printf("<%lld, %lld>\n", tmp.first, tmp.second);
    if (llabs(tmp.first) + llabs(tmp.second) < llabs(ans.first) + llabs(ans.second)) {
        ans = tmp;
    } else if (llabs(tmp.first) + llabs(tmp.second) == llabs(ans.first) + llabs(ans.second)) {
        ans = max(ans, tmp);
    }
}

void upd1(pair<llint, llint>& ans, pair<llint, llint> tmp, llint s1, llint s2, llint d1, llint d2) {
    llint dd = abs(tmp.first) + abs(tmp.second);
    for (int i = 52; i > 0; --i) {
        tmp.first += 1LL << i;
        tmp.second += 1LL << i;
        if (s1 <= tmp.first + tmp.second && tmp.first + tmp.second <= s2 &&
            d1 <= tmp.first - tmp.second && tmp.first - tmp.second <= d2 &&
            abs(tmp.first) + abs(tmp.second) == dd) {
            // noop
        } else {
            tmp.first -= 1LL << i;
            tmp.second -= 1LL << i;
        }
    }
    upd(ans, tmp);
}

void upd2(pair<llint, llint>& ans, pair<llint, llint> tmp, llint s1, llint s2, llint d1, llint d2) {
    //bool debug = tmp.first == -21 && tmp.second == -25;
    llint dd = abs(tmp.first) + abs(tmp.second);
    for (int i = 52; i > 0; --i) {
        tmp.first += 1LL << i;
        tmp.second -= 1LL << i;
       // if (debug) printf("[%d] = %lld, %lld\n", i, tmp.first, tmp.second);
        if (s1 <= tmp.first + tmp.second && tmp.first + tmp.second <= s2 &&
            d1 <= tmp.first - tmp.second && tmp.first - tmp.second <= d2 &&
            abs(tmp.first) + abs(tmp.second) == dd) {
         //   if (debug) printf("%lld, %lld, %lld, UPD\n", d1, d2, tmp.first - tmp.second);
            // noop
        } else {
            tmp.first -= 1LL << i;
            tmp.second += 1LL << i;
        }
    }
    upd(ans, tmp);
}

void uniq(vector<llint>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int main() {
    char ch;
    int re, n;
    pair<llint, llint> ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        ss = {-INF, 0, INF};
        dd = {-INF, 0, INF};
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld %c", &x[i], &y[i], &ch);
            ss.push_back(x[i] + y[i]);
            dd.push_back(x[i] - y[i]);
            z[i] = ch == '.' ? 0 : 1;
        }
        uniq(ss);
        uniq(dd);
        ans = {INF, INF};

        for (int i = 1; i < (int)ss.size(); ++i) {
            for (int j = 1; j < (int)dd.size(); ++j) {
                int mx = 3, my = 3;
                for (int k = 0; mx != 0 && my != 0 && k < n; ++k) {
                    bool byx = (ss[i - 1] >= x[k] + y[k]) == (dd[j - 1] >= x[k] - y[k]);
                    // printf("%d %d\n", k, byx);
                    if (byx) {
                        mx &= 1 << ((z[k] + x[k]) & 1);
                    } else {
                        my &= 1 << ((z[k] + y[k]) & 1);
                    }
                }
                //printf("[%lld, %lld] x [%lld, %lld]: %d: %d\n",
                //    ss[i - 1], ss[i], dd[j - 1], dd[j], mx, my);
                if (mx != 0 && my != 0) {
                    vector<llint> ms, md;
                    for (int k = 0; k < 8; ++k) {
                        ms.push_back(ss[i - 1] + k);
                        ms.push_back(ss[i] - k);
                        // ms.push_back(k - 3);
                        md.push_back(dd[j - 1] + k);
                        md.push_back(dd[j] - k);
                        // md.push_back(k - 3);
                    }
                    uniq(ms);
                    uniq(md);
                    for (llint s: ms) {
                        for (llint d: md) {
                            if (ss[i - 1] <= s && s <= ss[i] &&
                                dd[j - 1] <= d && d <= dd[j] &&
                                (s & 1) == (d & 1)) {
                                llint xx = (s + d) / 2;
                                llint yy = (s - d) / 2;
                                if ((mx & (1 << (xx & 1))) != 0 &&
                                    (my & (1 << (yy & 1))) != 0) {
                                    upd(ans, {xx, yy});
                                    upd1(ans, {xx, yy}, ss[i - 1], ss[i], dd[j - 1], dd[j]);
                                    upd2(ans, {xx, yy}, ss[i - 1], ss[i], dd[j - 1], dd[j]);
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("Case #%d: ", ri);
        if (ans.first < INF) {
            printf("%lld %lld\n", ans.first, ans.second);
        } else {
            puts("Too damaged");
        }
        fflush(stdout);
    }

    return 0;
}


