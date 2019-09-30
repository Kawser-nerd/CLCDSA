#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cassert>

using namespace std;

string alternate(int N, char ch1, char ch2) {
  string S;
  for (int i = 0; i < N; i++) {
    S += ch1;
    S += ch2;
  }
  return S;
}

string expand(const string& S, int N, char ch1, char ch2) {
  if (N == 0) return S;
  string T = alternate(N, ch1, ch2);
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == ch1) {
      return S.substr(0, i) + T + S.substr(i);
    }
  }
  return "";
}

string solve(int N, int R, int O, int Y, int G, int B, int V) {
  if (R + G == N && R == G) {
    return alternate(R, 'R', 'G');
  }
  if (Y + V == N && Y == V) {
    return alternate(Y, 'Y', 'V');
  }
  if (B + O == N && B == O) {
    return alternate(B, 'B', 'O');
  }

  bool fail = false;
  if (O > 0) {
    B -= O;
    if (B <= 0) {
      return "";
    }
  }
  if (G > 0) {
    R -= G;
    if (R <= 0) {
      return "";
    }
  }
  if (V > 0) {
    Y -= V;
    if (Y <= 0) {
      return "";
    }
  }

  vector<pair<int, char> > A;
  A.push_back(make_pair(R, 'R'));
  A.push_back(make_pair(Y, 'Y'));
  A.push_back(make_pair(B, 'B'));
  sort(A.rbegin(), A.rend());

  if (A[0].first > A[1].first + A[2].first) {
    return "";
  }

  string S(R + Y + B, '?');
  for (int i = 0; i < A[0].first; i++) {
    S[2 * i] = A[0].second;
  }
  for (int i = 2 * A[0].first - 1; i < R + Y + B; i++) {
    if (S[i - 1] == A[1].second) {
      S[i] = A[2].second;
      A[2].first--;
    } else {
      S[i] = A[1].second;
      A[1].first--;
    }
  }
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '?') {
      if (A[1].first > 0) {
        A[1].first--;
        S[i] = A[1].second;
      } else {
        A[2].first--;
        S[i] = A[2].second;
      }
    }
  }

  assert(A[1].first == 0);
  assert(A[2].first == 0);

  S = expand(S, O, 'B', 'O');
  S = expand(S, G, 'R', 'G');
  S = expand(S, V, 'Y', 'V');
  
  return S;
}

void check(const string& S, int R, int O, int Y, int G, int B, int V) {
  map<char, int> f;
  map<char, int> bts;
  f['R'] = R;
  f['O'] = O;
  f['Y'] = Y;
  f['G'] = G;
  f['B'] = B;
  f['V'] = V;
  bts['R'] = 0x001;
  bts['O'] = 0x011;
  bts['Y'] = 0x010;
  bts['G'] = 0x110;
  bts['B'] = 0x100;
  bts['V'] = 0x101;
  for (int i = 0; i < S.size(); i++) {
    if (--f[S[i]] < 0) {
      cerr << "FAIL CHECK" << endl;
      exit(1);
    }
  }
  for (auto i : f) {
    if (i.second > 0) {
      cerr << "FAIL CHECK 2" << endl;
      exit(1);
    }
  }
  for (int i = 0; i < S.size(); i++) {
    char ch = S[i];
    char nxt = S[(i + 1) % S.size()];

    if (bts[ch] & bts[nxt]) {
      cerr << "FAIL CHECK 3" << endl;
      exit(1);
    }
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, R, O, Y, G, B, V;
    cin >> N >> R >> O >> Y >> G >> B >> V;

    string S = solve(N, R, O, Y, G, B, V);
    if (S.size() == 0) {
      S = "IMPOSSIBLE";
    } else {
      check(S, R, O, Y, G, B, V);
    }
    cout << "Case #" << t << ": " << S << endl;
  }
  return 0;
}
