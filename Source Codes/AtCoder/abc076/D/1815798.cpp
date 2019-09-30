#include <iostream>
using namespace std;

const int N_MAX = 100;
double V[N_MAX+2];
double S_T[N_MAX+2];
double E_T[N_MAX+2];

double solve(int n) {
  double ans = 0;
  double prev_v = 0;
  for (int t = 0; t <= E_T[n+1]*2; t++) { // t is 0.5 unit
    double v = 100;
    double time = t;
    time /= 2;
    for (int j = 0; j < n+2; j++) {
      if (S_T[j] > time) {
	v = min(v, V[j] + S_T[j] - time);
      }
      else if (S_T[j] <= time && time < E_T[j]) {
	v = min(v, V[j]);
      }
      else if (E_T[j] <= time) {
	v = min(v, V[j] + time - E_T[j]);
      }
    }

    ans += 0.25*(v + prev_v);
    prev_v = v;

  }
  return ans;
}

int main() {
  int N;
  cin >> N;

  S_T[0] = 0;
  E_T[0] = 0;
  for (int i = 1; i < N+1; i++) {
    int t;
    cin >> t;
    S_T[i] = E_T[i-1];
    E_T[i] = t + S_T[i];
  }
  S_T[N+1] = E_T[N];
  E_T[N+1] = S_T[N+1];

  V[0] = 0;
  for (int i = 1; i < N+1; i++) {
    cin >> V[i];
  }
  V[N+1] = 0;

  printf("%.9lf\n", solve(N));
}