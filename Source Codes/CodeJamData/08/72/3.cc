#include <iostream>
#include <vector>
using namespace std;

int mod(int a) {
  a %= 10007;
  if (a < 0) a += 10007;
  return a;
}

int main()
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];
    while (v.size() > 2) {
      bool a0 = true, a1 = true;
      for (int i = 2; i + 1 < v.size(); i += 2)
	a0 = a0 && mod(v[i+1] - v[i]) == mod(v[1] - v[0]);
      for (int i = 3; i + 1 < v.size(); i += 2)
	a1 = a1 && mod(v[i+1] - v[i]) == mod(v[2] - v[1]);
      vector<int> w;
      if (a0 && a1) {
	break;
      } else if (a0) {
	if (v.size() % 2 == 1) {
	  cout << "Case #" << test << ": " << mod(v[v.size() - 1] + v[1] - v[0]) << endl;
	  goto next;
	}
	for (int i = 0; i < v.size(); i += 2)
	  w.push_back(v[i]);
      } else if (a1) {
	if (v.size() % 2 == 0) {
	  cout << "Case #" << test << ": " << mod(v[v.size() - 1] + v[2] - v[1]) << endl;
	  goto next;
	}
	for (int i = 1; i < v.size(); i += 2)
	  w.push_back(v[i]);
      } else {
	cout << "Case #" << test << ": " << "IMPOSSIBLE!" << endl;
	goto next;
      }
      v.swap(w);
    }
    cout << "Case #" << test << ": " << "UNKNOWN" << endl;
  next:
    ;
  }
}
