// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int x, y, k;
  cin >> x >> y >> k;
  int ans = min(k, y);
  k -= ans;
  ans += (x - k);
  cout << ans << endl;
	return 0;
}