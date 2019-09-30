#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const ll M = 1e9+7;

int main() {
  int N;
  ll A, B;
  vector<ll> a;
  vector<int> b;
  cin >> N >> A >> B;
  a.resize(N);
  for(int i = 0; i < N; i++)
    cin >> a[i];

  if(A == 1){
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++)
      cout << a[i] << endl;
    return 0;
  }

  b.resize(N);
  int mx = 0;
  int cnt = 0;
  for(int i = 0; i < a.size(); i++) {
    int tmp = a[i];
    b[i] = 0;
    while(tmp) {
      tmp /= A;
      b[i]++;
    }
    mx = max(mx, b[i]);
  }
  for(int i = 0; i < b.size(); i++) {
    cnt += mx - b[i];
  }
  if(cnt > B) {
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for(int i = 0; i < a.size(); i++) q.push(a[i]);
    for(int i = 0; i < B; i++) {
      ll tmp = q.top(); q.pop();
      q.push(tmp * A);
    }
    while(q.size()) {
      cout << q.top() % M << endl;
      q.pop();
    }
    return 0;
  }

  vector<ll> v;
  v.resize(N);
  B -= cnt;
  for(int i = 0; i < v.size(); i++) {
    ll tmp = a[i];
    for(int j = 0; j < mx-b[i]; j++) {
      tmp = tmp * A;
    }
    v[i] = tmp;
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < N; i++) {
    ll tmp = v[(i+B%N)%N] % M;
    int p = B/N + ((N-1-i) < B%N ? 1 : 0);
    ll x = A;
    while(p) {
      if(p & 1)
        tmp = (tmp * x) % M;
      x = (x * x) % M;
      p /= 2;
    }
    cout << tmp << endl;
  }
}