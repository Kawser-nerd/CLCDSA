#include <iostream>
#include <vector>
using namespace std;

long N, n;
vector<int> p;

int main(void) {
  cin >> N;

  for(n = 50; n > 0; n--) if(N >= (1L << n) - 1) break;
  N -= (1L << n) - 1;

  for(int i = 1; i <= n; i++) p.push_back(i);
  for(int i = 1; i <= n; i++) p.push_back(i);

  for(int i = n - 1; i >= 0; i--)
    if(N >= (1L << i)) {
      N -= (1L << i);
      n++;
      p.insert(p.begin() + i, n);
      p.push_back(n);
    }

  cout << p.size() << endl;
  for(int i = 0; i < p.size(); i++) cout << p[i] << " ";
  cout << endl;

  return 0;
}