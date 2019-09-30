#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
#define ll long long
#define ld long double

int main () {
  ll n, k;
  cin >> n >> k;  
  ld w[n], p[n];
  for (ll i = 0; i < n; i++) {
    cin >> w[i] >> p[i]; 
  }
  ld sum = 0;
  ld sug = 0;
  map<ll, ll> stand;
  for (ll i = 0; i < k; i++) {
    ld max = 0;
    ll itr = -1;
    for (ll j = 0; j < n; j++) {
      if (stand[j] == 0) {
        if (max <= (sug + w[j] * p[j]) / (sum + w[j])) {
          max = (sug + w[j] * p[j]) / (sum + w[j]);
          itr = j;  
        }  
      }  
    }    
    stand[itr] = 1;
    sum += w[itr];
    sug += w[itr] * p[itr];
  }
  cout << fixed << sug / sum << endl;
}