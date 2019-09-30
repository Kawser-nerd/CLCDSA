#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;
const int MAX = 100000;

int main() {
  int N, M, P, Y;
  cin >> N >> M;
  pair<pair<int, int>, int> city[MAX];
  pair<int, int> ans[MAX];
  for (int i = 0; i < M; i++) {
    cin >> P >> Y;
    city[i] = make_pair(make_pair(P, Y), i);
  }
  sort(city, city + M);
  for (int i = 0, c = 1; i < M;
       i++, c = i < M && city[i - 1].first.first == city[i].first.first ? c + 1
                                                                        : 1)
    ans[city[i].second] = make_pair(city[i].first.first, c);

  for (int i = 0; i < M; i++) {
    cout << setfill('0') << right << setw(6) << ans[i].first;
    cout << setfill('0') << right << setw(6) << ans[i].second;
    cout << endl;
  }
  return 0;
}