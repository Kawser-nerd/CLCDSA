#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;

int main()
{
  vector<tuple<int, int, int>> v;
  int h, w;
  cin >> h >> w;
  for (auto i = 1; i <= h; i++) {
    if (i % 2 != 0) {
      for (auto j = 1; j <= w; j++) {
	int a;
	cin >> a;
	v.emplace_back(make_tuple(i, j, a));
      }
    } else {
      stack<tuple<int, int, int>> s;
      for (auto j = 1; j <= w; j++) {
	int a;
	cin >> a;
	s.push(make_tuple(i, j, a));
      }
      for (auto j = 0; j < w; j++) {
	v.emplace_back(s.top());
	s.pop();
      }
    }
  }
  int pa = 0;
  int pi;
  int pj;
  int move_count = 0;
  vector<tuple<int, int, int, int>> ans;
  for (auto&& e : v) {
    if (pa % 2 == 0) {
      pi = get<0>(e);
      pj = get<1>(e);
      pa = get<2>(e);
    } else {
      ans.emplace_back(make_tuple(pi, pj, get<0>(e), get<1>(e)));
      move_count++;
      pa = get<2>(e) + 1;
      pi = get<0>(e);
      pj = get<1>(e);
    }
  }
  cout << move_count << endl;
  for (auto&& e : ans) {
    cout << get<0>(e) << " "
	 << get<1>(e) << " "
	 << get<2>(e) << " "
	 << get<3>(e) << endl;
  }
}