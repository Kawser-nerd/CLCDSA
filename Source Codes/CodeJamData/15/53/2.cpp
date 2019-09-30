#include <bits/stdc++.h>

using namespace std;

void normalize(vector < pair <int, int> > &a) {
  int cnt = a.size();
  sort(a.begin(), a.end());
  vector <bool> good(cnt, true);
  int max_speed = -1;
  for (int i = cnt - 1; i >= 0; i--) {
    if (a[i].second <= max_speed) {
      good[i] = false;
    }
    max_speed = max(max_speed, a[i].second);
  }
  int j = 0;
  for (int i = 0; i < cnt; i++) {
    if (good[i]) {
      a[j++] = a[i];
    }
  }
  a.resize(j);
}

const double inf = 1e30;
const int N = 505;

int pp[N];
double fp[N][N], fn[N][N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int y, n;
    scanf("%d %d", &y, &n);
    vector < pair <int, int> > pos;
    vector < pair <int, int> > neg;
    pos.push_back(make_pair(0, y));
    neg.push_back(make_pair(0, y));
    for (int i = 0; i < n; i++) {
      scanf("%d", pp + i);
    }
    for (int i = 0; i < n; i++) {
      int ss;
      scanf("%d", &ss);
      if (pp[i] > 0) {
        pos.push_back(make_pair(pp[i], ss));
      } else {
        neg.push_back(make_pair(-pp[i], ss));
      }
    }
    normalize(pos);
    normalize(neg);
    int cntp = pos.size() - 1;
    int cntn = neg.size() - 1;
    for (int i = 0; i <= cntp; i++) {
      for (int j = 0; j <= cntn; j++) {
        fp[i][j] = inf;
        fn[i][j] = inf;
      }
    }
    fp[0][0] = fn[0][0] = 0.0;
    for (int i = 0; i <= cntp; i++) {
      for (int j = 0; j <= cntn; j++) {
        for (int rot = 0; rot < 2; rot++) {
          double fts = (rot == 0 ? fp[i][j] : fn[i][j]);
          if (fts == inf) {
            continue;
          }
          int ii = i, jj = j;
          double at = (rot == 0 ?  pos[i].first + pos[i].second * fts
                                : -neg[j].first - neg[j].second * fts);
          while (ii < cntp) {
            double him = pos[ii + 1].first + pos[ii + 1].second * fts;
            if (him < at) {
              ii++;
            }
            else break;
          }
          while (jj < cntn) {
            double him = -neg[jj + 1].first - neg[jj + 1].second * fts;
            if (him > at) {
              jj++;
            }
            else break;
          }
          if (ii == cntp && jj == cntn) {
            fp[ii][jj] = min(fp[ii][jj], fts);
          }
          if (ii < cntp) {
            double him = pos[ii + 1].first + pos[ii + 1].second * fts;
            double ft = fts;
            if (him > at) {
              ft += (him - at) / (y - pos[ii + 1].second);
            }
            if (ft < fp[ii + 1][jj]) {
              fp[ii + 1][jj] = ft;
            }
          }
          if (jj < cntn) {
            double him = -neg[jj + 1].first - neg[jj + 1].second * fts;
            double ft = fts;
            if (him < at) {
              ft += (at - him) / (y - neg[jj + 1].second);
            }
            if (ft < fn[ii][jj + 1]) {
              fn[ii][jj + 1] = ft;
            }
          }
        }
      }
    }
    double ans = min(fp[cntp][cntn], fn[cntp][cntn]);
    printf("%.17f\n", ans);
  }
  return 0;
}
