#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > vvi;

int C, R, c, r;

int recur(const vvi& V);

inline bool bound(int ri, int ci)
{
  return 0 <= ri && ri < R && 0 <= ci && ci < C;
}

int find_max(const vvi& V, int ri, int ci, int& rri, int& rci)
{
  int max = 0;
  if (bound(ri-1,ci)) {
    int v = V[ri-1][ci];
    if (v > max) {
      max = v;
      rri = ri-1;
      rci = ci;
    }
  }
  if (bound(ri,ci-1)) {
    int v = V[ri][ci-1];
    if (v > max) {
      max = v;
      rri = ri;
      rci = ci-1;
    }
  }
  if (bound(ri,ci+1)) {
    int v = V[ri][ci+1];
    if (v > max) {
      max = v;
      rri = ri;
      rci = ci+1;
    }
  }
  if (bound(ri+1,ci)) {
    int v = V[ri+1][ci];
    if (v > max) {
      max = v;
      rri = ri+1;
      rci = ci;
    }
  }
  return max;
}

int use(vvi& nV, const vvi& V, int ri, int ci, int maxn)
{
  if (maxn == -1) return maxn;
  if (!bound(ri, ci)) return maxn;
  int x = nV[ri][ci];
  nV[ri][ci] -= V[r][c];
  if (nV[ri][ci] < 0) nV[ri][ci] = 0;
  int v = recur(nV);
  if (v != -1) {
    v = max(maxn, v);
  }
  nV[ri][ci] = x;
  return v;
}

int recur(const vvi& V) {
  //cout << V[r][c] << endl;
  if (V[r][c] <= 0) {
    return 0;
  }
  int ri, ci;
  int m = find_max(V, r, c, ri, ci);
  //cout << m << endl;
  if (m == 0) {
    return -1;
  }
  vvi nV = V;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (i == r && j == c) continue;
      int v = V[i][j];
      if (v > 0) {
        m = find_max(V, i, j, ri, ci);
        if (m > 0) {
          nV[ri][ci] -= v;
          if (nV[ri][ci] < 0) nV[ri][ci] = 0;
        }
      }
    }
  }
  if (nV[r][c] == 0) return 0;
  int maxn = 0;
  //cout << "N" << endl;
  maxn = use(nV, V, r-1, c, maxn);
  //cout << "W" << endl;
  maxn = use(nV, V, r, c-1, maxn);
  //cout << "E" << endl;
  maxn = use(nV, V, r, c+1, maxn);
  //cout << "S" << endl;
  maxn = use(nV, V, r+1, c, maxn);
  if (maxn == -1)
    return maxn;
  else
    return maxn+1;
}

int main()
{
  int ncase;
  cin >> ncase;

  for (int cas = 1; cas <= ncase; cas++) {
    cin >> C >> R >> c >> r;
    c--;
    r--;
    vector<vector<int> > V;
    for (int i = 0; i < R; i++) {
      V.push_back(vector<int>());
      for (int j = 0; j < C; j++) {
        int pow;
        cin >> pow;
        V[i].push_back(pow);
      }
    }

    int n = recur(V);
    cout << "Case #" << cas << ": ";
    if (n == -1)
      cout << "forever" << endl;
    else
      cout << n << " day(s)" << endl;
  }

  return 0;
}

