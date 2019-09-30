#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k; cin >> n >> k;
  int len = 0;
  vector<int> iv;

  for (int i = 0; i < n; i++) {
    int l; cin >> l;
    iv.push_back(l);
  }

  sort(iv.begin(), iv.end(), greater<int>());

  for (int i = 0; i < k; i++) len += iv[i];

  cout << len << endl;
  return 0;
}