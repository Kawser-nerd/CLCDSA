#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 1000;
int N, S, P;
int totals[N_MAX];

void solve_case(int case_num) {
  cin >> N >> S >> P;
  for (int i = 0; i < N; i++)
    cin >> totals[i];

  sort(totals, totals + N);

  int answer = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (totals[i] < P)
      continue;

    if (totals[i] >= 3 * P - 2) {
      answer++;
      continue;
    }

    if (S > 0 && totals[i] >= 3 * P - 4) {
      answer++;
      S--;
    }
  }

  cout << "Case #" << case_num + 1 << ": " << answer << '\n';
}


int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    solve_case(i);
  }
}
