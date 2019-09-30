#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
#define MAX_N 100000
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  ll t[n], d[n];
  for(int i = 0; i < n; i++) cin >> t[i] >> d[i];

  vector< pll > a;
  for(int i = 0; i < n; i++){
    a.push_back(make_pair(d[i], t[i]));
  }

  sort(a.begin(), a.end(), greater< pll >());

  bool used[n + 1];
  fill(used, used + n + 1, false);

  int count = 0;
  ll sum = 0;
  priority_queue< 
    pii, vector< pll >, greater< pll > > pq;
  for(int i = 0; i < k; i++){
    pii p = a[i];
    sum += p.first;
    if(!used[p.second]) ++count;
    else pq.push(p);
    used[p.second] = true;
  }

  ll best = sum + (ll)count * count;

  for(int i = k; i < n && !pq.empty(); i++){
    if(!used[a[i].second]){
      sum -= pq.top().first;
      pq.pop();
      sum += a[i].first;
      ++count;
      used[a[i].second] = true;
      best = max(best, sum + (ll)count * count);
    }
  }

  cout << best << endl;

  return 0;
}