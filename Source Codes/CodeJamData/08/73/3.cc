#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ii;

double p[30][4];
vector<double> allp;
int Q;

int main() {
  int C; cin >> C;
  int M;
  for (int it = 1; it <= C; it++) {
    cin >> M >> Q;

    for (int i = 0; i < Q; i++)
      for (int j = 0; j < 4; j++)
	cin >> p[i][j];

    allp.clear();

    for (int i = 0; i < 4; i++)
      allp.push_back(p[0][i]);
    sort(allp.rbegin(), allp.rend());
    if (allp.size() > M) allp.resize(M);
    
    for (int i = 1; i < Q; i++) {
      vector<double> nextp;
      for (int j = 0; j < allp.size(); j++) {
	for (int k = 0; k < 4; k++) {
	  nextp.push_back(allp[j] * p[i][k]);
	}
      }
      sort(nextp.rbegin(), nextp.rend());
      if (nextp.size() > M) nextp.resize(M);
      allp = nextp;
    }

    double ret = 0;
    for (int i = 0; i < allp.size(); i++) {
      ret += allp[i];
    }

    printf("Case #%d: %.6lf\n", it, ret);
  }
}
