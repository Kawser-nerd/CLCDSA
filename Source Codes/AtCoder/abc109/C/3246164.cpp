#include <iostream>
#include <deque>

using namespace std;

int gcd(int a, int b) {
  int tmp;
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  int r = -1;
  while (r != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int ans(deque<int> vs) {
  if (vs.size() == 1) {
    return vs[0];
  }

  int ans = gcd(vs[0], vs[1]);

  // pop_front 2 times
  vs.pop_front();
  vs.pop_front();

  while (!vs.empty()) {
    ans = gcd(ans, vs[0]);
    vs.pop_front();
  }

  return ans;
}

int main(int argc, char const* argv[])
{
  int n, x;

  cin >> n >> x;

  deque<int> vs;
  int v;

  while (n--) {
    cin >> v;
    vs.push_back(abs(v - x));
    // cout << "v: " << v << endl;
  }

  cout << ans(vs) << endl;

  return 0;
}