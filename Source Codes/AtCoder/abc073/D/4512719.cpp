#include <iostream>
using namespace std;
#define ll long long
#define inf 1<<29

int main () {
  ll n, m, r;
  cin >> n >> m >> r;
  ll rr[r];
  for (ll i = 0; i < r; i++) {
    cin >> rr[i];  
  }    
  sort(rr, rr + r);
  ll length[n + 1][n + 1];
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= n; j++) {
      length[i][j] = inf;  
    }  
    length[i][i] = 0;
  }
  for (ll i = 0; i < m; i++) {
    ll s, ss, sss;
    cin >> s >> ss >> sss;
    if (length[s][ss] > sss) {
    	length[s][ss] = sss;
    	length[ss][s] = sss;
    }
  }
  for (ll k = 1; k <= n; k++) {
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        if (length[i][j] > length[i][k] + length[k][j]) {
          length[i][j] = length[i][k] + length[k][j];  
        }  
      }  
    }  
  }
  ll min = -1;
  do {
    ll dis = 0;
    for (ll i = 1; i < r; i++) {
      dis += length[rr[i - 1]][rr[i]];
    }  
    if (min == -1 || min > dis) {
      min = dis;  
    }
  } while (next_permutation(rr, rr + r));
  cout << min << endl;

}