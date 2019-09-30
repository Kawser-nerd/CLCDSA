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

double probs[50000];
double p[30][4];

int main(void) {

  int C;
  cin >> C;
  for (int c = 1; c <= C; c++) {
    int Q, M;
    cin >> M >> Q;
    for (int q = 0; q < Q; q++)
      for (int k = 0; k < 4; k++)
	cin >> p[q][k];
    probs[0] = 1.0;
    for (int i = 1; i < M; i++)
      probs[i] = 0.0;

    for (int q = 0; q < Q; q++) {
      /*
      for (int i = 0; i < M; i++)
	cerr << probs[i] << " ";
      cerr << endl;
      */
      for (int i = 0; i < M; i++)
	for (int k = 0; k < 4; k++)
	  probs[i+(k+1)*M] = probs[i]*p[q][k];
      sort(probs+M, probs+5*M);
      for (int i = 0; i < M; i++)
	probs[i] = probs[i+4*M];
    }

    double ans = 0.0;
    for (int i = 0; i < M; i++)
      ans += probs[i];
    printf("Case #%d: %f\n", c, ans);
  }

}
