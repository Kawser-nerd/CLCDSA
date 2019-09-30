#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

pair<string, vector<int> > decomp(const string& S) {
  string R;
  vector<int> Q;
  for(int i = 0; i < S.size(); i++) {
    if(i == 0 || S[i] != S[i - 1]) {
      R += S[i];
      Q.push_back(1);
    } else {
      Q[Q.size() - 1]++;
    }
  }
  return make_pair(R, Q);
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    set<string> st;
    vector<vector<int> > A;
    for(int i = 0; i < N; i++) {
      string S; cin >> S;
      pair<string, vector<int> > res = decomp(S);
      st.insert(res.first);
      A.push_back(res.second);
    }

    printf("Case #%d: ", t);
    if(st.size() != 1) {
      printf("Fegla Won\n");
    } else {
      int result = 0;
      int M = A[0].size();
      for(int i = 0; i < M; i++) {
        vector<int> B;
        for(int j = 0; j < N; j++) {
          B.push_back(A[j][i]);
        }
        sort(B.begin(), B.end());

        int x = B[N / 2];
        for(int j = 0; j < N; j++) {
          result += abs(B[j] - x);
        }
      }

      printf("%d\n", result);
    }
  }
  return 0;
}
