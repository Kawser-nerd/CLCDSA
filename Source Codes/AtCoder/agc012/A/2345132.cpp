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

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[3 * n];
  for(int i = 0; i < 3 * n; i++){
    cin >> a[i];
  }

  sort(a, a + 3 * n);
  ll sum = 0;
  int j = 3 * n - 2;
  for(int i = 0; i < n; i++){
    sum += (ll)a[j];
    j -= 2;
  }

  cout << sum << endl;

  return 0;
}