#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 80

bool USED[MAXN];
int C[MAXN];
int S[MAXN];
int T[MAXN];

int main() {
  int TT; cin >> TT;
  for(int t = 1; t <= TT; t++) {
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> C[i] >> S[i] >> T[i];
    cin >> M;
    for(int i = N; i < N + M; i++) cin >> C[i] >> S[i] >> T[i];
    memset(USED, 0, sizeof(USED));

    int result = 0;
    int cards = N;
    int score = 0;
    int time = 1;
    while(1) {
      int bestc = -1;
      vector<int> SCR;
      for(int i = 0; time > 0 && i < min(cards, N + M); i++) {
        if(!USED[i]) {
          if(T[i] > 0) {
            cards += C[i];
            score += S[i];
            time += T[i] - 1;
            USED[i] = true;
          } else if(C[i] > 0) {
            if(bestc == -1 || S[i] > S[bestc]) {
              bestc = i;
            }
          } else {
            SCR.push_back(S[i]);
          }
        }
      }
      sort(SCR.rbegin(), SCR.rend());
      int sum = 0;
      for(int i = 0; i < time && i < SCR.size(); i++) {
        sum += SCR[i];
      }
      result = max(result, score + sum);

      if(time == 0 || bestc == -1) {
        break;
      } else {
        USED[bestc] = true;
        score += S[bestc];
        cards += C[bestc];
        time--;
      }
    }
    printf("Case #%d: %d\n", t, result);
  }
}
