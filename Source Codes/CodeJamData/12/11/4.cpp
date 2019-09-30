/*
ID: Plagapong
LANG: C++
TASK: password
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999

using namespace std;
int a, b;
double p[100005];
double correct[100005];

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  correct[0] = 1;
}

void process() {
  // Code here!
  int garbage = scanf("%d%d", &a, &b);
  correct[0] = 1 + b;
  for (int i = 1; i <= a; i++) {
    garbage = scanf("%lf", &p[i]);
    correct[i] = correct[i-1] * p[i];
  }
  double best = 2 + b;
  for (int i = 0; i <= a; i++) {
    double better = (2 * b + 2 - a) + 2 * (a-i) - correct[i];
    if (better < best) {
      best = better;
    }
  }
  printf("%.10lf", best);
}

int main() {
  preprocess();
  int times;
  cin >> times;
  for (int i = 1; i <= times; i++) {
	cout << "Case #" << i << ": ";
	clearVars();
	process();
	cout << endl;
  }
  return 0;
}
