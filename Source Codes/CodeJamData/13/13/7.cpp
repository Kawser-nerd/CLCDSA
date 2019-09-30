#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <cmath>

using namespace std;

#define MAXR 10000

map<int, int> CNT[MAXR];

int RES[MAXR][12];

int A[12];
double P[MAXR];
double PBASE[MAXR];

bool F[10] = {false, true, true, true, true,
              false, true, false, true, false};

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int R, N, M, K;
    cin >> R >> N >> M >> K;

    int rsz = 0;
    for(A[0] = 1; A[0] <= M; A[0]++)
    for(A[1] = A[0]; F[A[0]] && A[1] <= M; A[1]++)
    for(A[2] = A[1]; F[A[1]] && A[2] <= M; A[2]++)
    for(A[3] = A[2]; F[A[2]] && A[3] <= M; A[3]++)
    for(A[4] = A[3]; F[A[3]] && A[4] <= M; A[4]++)
    for(A[5] = A[4]; F[A[4]] && A[5] <= M; A[5]++)
    for(A[6] = A[5]; F[A[5]] && A[6] <= M; A[6]++)
    for(A[7] = A[6]; F[A[6]] && A[7] <= M; A[7]++)
    for(A[8] = A[7]; F[A[7]] && A[8] <= M; A[8]++)
    for(A[9] = A[8]; F[A[8]] && A[9] <= M; A[9]++)
    for(A[10] = A[9]; F[A[9]] && A[10] <= M; A[10]++)
    for(A[11] = A[10]; F[A[10]] && A[11] <= M; A[11]++) {
      for(int i = 0; i < N; i++) {
        RES[rsz][i] = A[i];
      }
      for(int i = 0; i < 1 << N; i++) {
        int m = 1;
        for(int j = 0; j < N; j++) {
          if(i & 1 << j) {
            m *= A[j];
          }
        }
        ++CNT[rsz][m];
      }

      PBASE[rsz] = 0;
      for(int i = 1; i <= N; i++) {
        PBASE[rsz] += log(i);
      }
      for(int i = 0; i < N; ) {
        int sz = 1;
        for(; i + sz < N && A[i] == A[i + sz]; ) {
          PBASE[rsz] -= log(++sz);
        }
        i += sz;
      }

      rsz++;
    }

    cout << "Case #" << t << ":" << endl;
    for(int i = 0; i < R; i++) {
      int fv = 0;
      int sv = 0;
      
      memcpy(P, PBASE, sizeof(P));
      for(int j = 0; j < K; j++) {
        long long m; cin >> m;

        int mfv, msv;
        for(mfv = 0; m % 5 == 0; mfv++) m /= 5;
        for(msv = 0; m % 7 == 0; msv++) m /= 7;
        fv = max(mfv, fv);
        sv = max(msv, sv);

        for(int k = 0; k < rsz; k++) {
          typeof(CNT[k].begin()) it = CNT[k].find(m);
          if(it == CNT[k].end()) {
            P[k] = -1e300;
          } else {
            P[k] += log(it->second);
          }
        }
      }
      if(fv + sv > 0) for(int j = 0; j < rsz; j++) {
        if(RES[j][fv + sv - 1] != 1) {
          P[j] = -1e300;
        }
      }
      if(fv + sv < 12) for(int j = 0; j < rsz; j++) {
        if(RES[j][fv + sv] == 1) {
          P[j] = -1e300;
        }
      }
      
      int mi = max_element(P, P + rsz) - P;
      for(int j = fv + sv; j < 12; j++) {
        cout << (char)('0' + max(2, RES[mi][j]));
      }
      for(int j = 0; j < fv; j++) cout << '5';
      for(int j = 0; j < sv; j++) cout << '7';

      cout << endl;
    }
  }
  return 0;
}
