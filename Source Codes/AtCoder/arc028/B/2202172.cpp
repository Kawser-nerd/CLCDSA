#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

typedef pair< int, int > pp;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int x[n];
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }

  priority_queue< pp > pq;
  for(int i = 0; i < k; i++){
    pq.push(make_pair(x[i], i));
  }

  string ans;
  for(int i = 0; i < n - k + 1; i++){
    ans += to_string(pq.top().second + 1) + "\n";
    pp p = pq.top();
    if(x[i + k] < p.first){
      pq.push(make_pair(x[i + k], i + k));
      pq.pop();
    }
  }

  cout << ans;

  return 0;
}