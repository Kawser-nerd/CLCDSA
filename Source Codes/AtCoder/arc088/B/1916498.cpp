#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char *argv[argc])
{
  string S;

  cin >> S;

  char prev_c = '0';
  vector<int> flip_index;
  int ans = S.size();
  
  FOR(i, S.size()) {
    if (S[i] != prev_c &&
        MAX(i, S.size() - i) < ans)
      ans = MAX(i, S.size() - i);
    prev_c = S[i];
  }

  cout << ans << endl;
  
  return 0;
}