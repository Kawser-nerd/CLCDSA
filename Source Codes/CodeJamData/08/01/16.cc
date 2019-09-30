#include <iostream>
#include <string>

using namespace std;

int main() {
  int N; cin >> N;
  for (int c = 1; c <= N; ++c) {
    int S; cin >> S; cin.ignore();
    string engines[100];
    for (int i = 0; i < S; ++i)
      getline(cin, engines[i]);
    int Q; cin >> Q; cin.ignore();
    int scores[100] = {0}, best = 0;
    for (int i = 0; i < Q; ++i) {
      string query; getline(cin, query);
      for (int j = 0; j < S; ++j)
        if (query != engines[j]) {
          if (best+1 < scores[j])
            scores[j] = best+1;
          }
        else scores[j] = 1000000;
      best = 1000000;
      for (int j = 0; j < S; ++j)
        if (scores[j] < best)
          best = scores[j];
      }
    cout << "Case #" << c << ": " << best << "\n";
    }
  }