#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int N, K;
int A[100010];

vector<int> getDiffs(vector<int> ds) {
  set<int> temp;
  for (size_t i = 0; i+1 < ds.size(); i++) {
    auto d = ds[i+1] - ds[i];
    if(d) temp.insert(d);
  }
  vector<int> new_ds;
  int first = *(temp.begin());
  new_ds.push_back(first);
  for (auto &&d:temp) {
    if(d%first) new_ds.push_back(d);
  }
  sort(new_ds.begin(),new_ds.end());
  return new_ds;
}

int main (int argc, char const *argv[])
{
  cin >> N >> K;
  set<int> as;
  for(int i=0;i<N;++i) {
    cin >> A[i];
    as.insert(A[i]);
  }
  int maxA = *as.rbegin();
  sort(A,A+N);
  vector<int> diffs;
  diffs.assign(A,A+N);
  for (size_t i = 0; i < 1000; i++) {
    diffs = getDiffs(diffs);
    if(diffs.size()<2) break;
  }
  if(as.count(K)) {
    cout << "POSSIBLE" << endl;
    return 0;
  } else {
    if(K>maxA) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    } else {
      for(auto &&d:diffs) {
        if(K%d==0){
          cout << "POSSIBLE" << endl;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}