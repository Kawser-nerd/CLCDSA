#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#define ll long long
#define endl '\n'
using namespace std;

int main(void)
{
  cin.tie(NULL); ios_base::sync_with_stdio(false);
  int N; cin >> N;
  ll ret = 0;
  while(N--)
    {
      int l, r; cin >> l >> r;
      ret += (r - l) + 1;
    }

  cout << ret << endl;
  return 0;
}