#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> p;

bool comp(const p& x, const p& y) {
  return x.first < y.first;
}

int main() {
  int N;
  ull M;
  cin >> N >> M;

  vector<p> infos;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    p x = make_pair(a, b);
    infos.push_back(x);
  }
  sort(infos.begin(),
       infos.end(),
       comp);

  ull ans = 0;
  for (int i = 0; i < N; i++) {    
    p x = infos[i];
    if (M <= x.second) {
      ans += x.first * M;
      break;
    }
    else {
      ans += x.first * x.second;
      M -= x.second;
    }
  }
  cout << ans << endl;
}