#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

const int M = 10000;

int main(void)
{
  int NUM_CASES;
  cin >> NUM_CASES;
  for (int c = 1; c <= NUM_CASES; c++) {
    int N;
    cin >> N;
    int ans = 0;
    vector < vector <int> > breq(M+1, vector <int> ());
    vector < vector <int> > creq(M+1, vector <int> ());
    vector <int> A, B, C;
    for (int i = 0; i < N; i++) {
      int a, b, c; cin >> a >> b >> c;
      A.push_back(a); B.push_back(b); C.push_back(c);
      breq[b].push_back(i);
      creq[c].push_back(i);
    }
    for (int a = 0; a <= M; a++) {
      vector <int> happy(N);
      int tans = 0;
      for (int i = 0; i < N; i++)
	if (A[i] <= a && B[i] == 0 && C[i] <= M-a) {
	  happy[i] = 1;
	  tans++;
	}
      if (tans > ans) ans = tans;
      for (int b = 1; a+b <= M; b++) {
	int c = M-a-b;
	for (int j = 0; j < breq[b].size(); j++) {
	  int ind = breq[b][j];
	  int h = (A[ind] <= a && C[ind] <= c ? 1 : 0);
	  if (happy[ind] != h) {
	    tans += h-happy[ind];
	    happy[ind] = h;
	  }
	}
	for (int j = 0; j < creq[c+1].size(); j++) {
	  int ind = creq[c+1][j];
	  int h = 0;
	  if (happy[ind] != h) {
	    tans += h-happy[ind];
	    happy[ind] = h;
	  }
	}
	if (tans > ans) ans = tans;
      }
    }
    printf("Case #%d: %d\n", c, ans);
  }
}
