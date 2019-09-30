#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

const double eps = 1e-9;
const double inf = 1e5;

char lane[50][50];
char visited[50][50];
double collide_start[50][50];
double collide_end[50][50];
double cur_time;
int N;
int C[50], S[50], P[50];

bool dfs(int a, int b, int req) {
  if (lane[a][b] != -1 && req != -1 && lane[a][b] != req) return false;
  if (visited[a][b]) return true;
  if (lane[a][b] == -1) lane[a][b] = max(req, 0);
  visited[a][b] = 1;

  // dfs neighbors
  if (collide_start[a][b] < cur_time + eps) {
    if (!dfs(b, a, 1-lane[a][b]))
      return false;
    for (int c = 0; c < N; c++) {
      if (c == a || c == b) continue;
      if (collide_start[a][c] < cur_time + eps &&
	  collide_start[a][c] < collide_end[a][b] - eps &&
	  collide_start[a][b] < collide_end[a][c] - eps) {
	if (!dfs(a, c, lane[a][b]))
	  return false;
      }
    }
  }

  return true;
}

bool compute(double t) {
  memset(lane, -1, sizeof(lane));
  memset(visited, 0, sizeof(visited));
  cur_time = t;
  for (int a = 0; a < N; a++)
    for (int b = a+1; b < N; b++)
      if (abs(P[a]-P[b]) < 5)
	if (!dfs(a, b, C[a]))
	  return false;
  for (int a = 0; a < N; a++)
    for (int b = 0; b < N; b++)
      if (b != a && !dfs(a, b, -1))
	return false;
  return true;
}

int main(void) {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      char c; cin >> c; C[i] = (c == 'L' ? 0 : 1);
      cin >> S[i] >> P[i];
    }
    vector <double> collide_starts;
    for (int a = 0; a < N; a++)
      for (int b = 0; b < N; b++) {
	if (S[a] == S[b]) {
	  if (abs(P[a]-P[b]) < 5) {
	    collide_start[a][b] = 0;
	    collide_end[a][b] = inf;
	  }
	  else {
	    collide_start[a][b] = inf;
	    collide_end[a][b] = inf;
	  }
	}
	else {
	  double t1 = (P[b]-P[a]-5.0)/(S[a]-S[b]);
	  double t2 = (P[b]-P[a]+5.0)/(S[a]-S[b]);
	  if (t1 > t2) swap(t1, t2);
	  if (t2 <= 0) {
	    collide_start[a][b] = inf;
	    collide_end[a][b] = inf;
	  }
	  else if (t1 < 0) {
	    collide_start[a][b] = 0;
	    collide_end[a][b] = t2;
	  }
	  else {
	    collide_start[a][b] = t1;
	    collide_end[a][b] = t2;
	    collide_starts.push_back(t1);
	  }
	}
      }
    sort(collide_starts.begin(), collide_starts.end());

    bool ok = true;
    for (int i = 0; i < (int) collide_starts.size(); i++) {
      ok = compute(collide_starts[i]);
      if (!ok) {
	printf("Case #%d: ", t); cout << collide_starts[i] << endl;
	break;
      }
    }
    if (ok)
      printf("Case #%d: Possible\n", t);
  }
}
