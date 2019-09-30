#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> comb(vector<int> &v, int r)
{
  set<vector<int>> outer;

  if (v.size() < r) {
    return outer;
  }
  if (v.size() == r) {
    outer.insert(v);
    return outer;
  }

  vector<bool> v_use(v.size());
  fill(v_use.begin(), v_use.begin() + r, true);
  do {
    vector<int> inner;
    for (int i = 0; i < v.size(); ++i) {
      if (v_use[i]) {
        inner.push_back(v[i]);
      }
    }
    outer.insert(inner);
  } while (std::prev_permutation(v_use.begin(), v_use.end()));

  return outer;
}

int main(int argc, char const* argv[])
{
  int N, M;
  cin >> N >> M;

  set<vector<int>> acq;
  for (int i = 0; i < M; i++) {
    vector<int> a(2);
    cin >> a[0] >> a[1];
    acq.insert(a);
  }

  int max = 1;
  for (int i = 0; i < pow(2, N); i++) {
    vector<int> mem;
    for (int j = 0, k = i; k != 0; k >>= 1, j++) {
      if (k % 2 == 1) {
        mem.push_back(j + 1);
      }
    }

    set<vector<int>> rels = comb(mem, 2);
    bool contain = true;
    for (auto&& rel : rels) {

      if (acq.find(rel) == acq.end()) {
        // acq not contain rel
        contain = false;
        break;
      }
    }
    if (contain) {
      max = mem.size() > max ? mem.size() : max;
    }
  }

  cout << max << endl;

  return 0;
}