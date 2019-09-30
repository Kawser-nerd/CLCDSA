#include <time.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  ll N, x;
  cin >> N >> x;
  vector<ll> a(N);
  for (size_t i = 0; i < a.size(); i++) {
    ll temp = 0;
    scanf("%lld", &temp);
    a[i] = temp;
    // cout<<temp<<endl;
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (size_t i = 0; i < a.size(); i++) {
    // cout<<a[i]<<endl;
    if (x >= a[i]) {
      ans++;
      x = x - a[i];
      //cout << ans << endl;
    } else {
      // cout << "break" << endl;
      break;
    }
    if (i == a.size() - 1 && x != 0) {
      ans--;
    }
  }
  cout << ans << endl;

  return 0;
}