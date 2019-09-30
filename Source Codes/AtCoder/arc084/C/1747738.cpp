#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int k, n;
  cin >> k >> n;

  vector<int> ans;

  if (k % 2 == 0) {
    ans = vector<int>(n, k);
    ans[0] = k / 2;
  } else {
    ans = vector<int>(n, (k+1)/2);
    for (int i = 0; i < n/2; i++) {
	  if (ans[ans.size()-1] == 1) {
	    ans.erase(ans.end() - 1);
	  } else {
	    ans[ans.size()-1] -= 1;
		while (ans.size() < n) {
		  ans.push_back(k);
		}
      }
	}
  }

  cout << ans[0];
  for (int i = 1; i < ans.size(); i++)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}