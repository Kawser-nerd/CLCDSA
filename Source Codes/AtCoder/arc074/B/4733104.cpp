#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long unsigned int ll;
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define amari(x) ((x) % 1000000007)

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end());
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<int>());
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin();
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin();

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define isValidPoint(x, y, mx, my) x >= 0 && x  < mx && y >= 0 && y < my

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n;
long a[200000];
long scores[100001];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  fillLong(a, n*3); 
  
  priority_queue<long, vector<long>, greater<long> > pf;
  priority_queue<long> pb;

  long sf = 0;
  long sb = 0;

  for (int i = 0; i < n; i++) {
    pf.push(a[i]);
    pb.push(a[3 * n - i - 1]);
    sf += a[i];
    sb += a[3 * n - i - 1];
  }

  scores[0] = sf;

  for (int i = n; i < 2 * n; i++) {
    sf += a[i];
    pf.push(a[i]);
    sf -= pf.top(); pf.pop();
    scores[i - n + 1] = sf;
  }

  scores[n] -= sb;

  for (int i = 2 * n - 1; i >= n; i--) {
    sb += a[i];
    pb.push(a[i]);
    sb -= pb.top(); pb.pop();
    scores[i - n] -= sb;
  }

  printf("%ld\n", *max_element(scores, scores + n + 1));

  return 0;
}