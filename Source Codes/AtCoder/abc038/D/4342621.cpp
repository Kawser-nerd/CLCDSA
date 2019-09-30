#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main () {
  ll n;
  cin >> n;  
  pair<ll, ll> box[100000];
  for (ll i = 0; i < n; i++) {
    ll s, ss;
    cin >> s >> ss;
    box[i] = make_pair(s, -1 * ss);  
  }
  sort(box, box + n);
  pair<ll, ll> lis[100000];
  for (ll i = 0; i < n; i++) {
    lis[i] = make_pair(100001, 100001);
    box[i].second *= -1;
  }
  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      lis[i] = make_pair(box[i].second, box[i].first);  
    }  
    else {
      // ???????.
      ll now = box[i].second;
      ll left = -1;
      ll right = n;
      while (left < right - 1) {
        ll mid = (left + right) / 2;
        if (lis[mid].first < now) {
          left = mid;  
        }  
        else {
          right = mid;  
        }
      }  
      lis[left + 1] = make_pair(now, box[i].first);
    }
  }
  ll max = 0;
  for (ll i = 0; i < n; i++) {
    if (lis[i].first <= 100000) {
      max++;  
    }
  }
  cout << max << endl;
}