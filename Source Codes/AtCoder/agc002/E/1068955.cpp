#pragma optimization_level 3
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100010];

inline bool u(int x, int y) {
  if (A[x] <= y) return true;
  return !u(x, y+1);
}
inline bool r(int x, int y) {
  if (x >= N || A[x] <= y) return true;
  return !r(x+1, y);
}

int main() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N, greater<int>());
  int i = 0;
  while (i < N-1 && A[i+1] > i+1) i++;
  cout << (!(r(i+1,i) && u(i,i+1)) ? "First\n" : "Second\n");
  return 0;
}