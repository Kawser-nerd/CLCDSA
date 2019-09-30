// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
 
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())
 
#ifdef __DEBUG
#define debug if (true)
#else
#define debug if (false)
#endif
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char board[305][305];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> board[i];
  }

  int answer = 0;

  for (int c = 0; c < N; ++c) {
    bool check = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[(i + c) % N][j] != board[(j + c) % N][i]) {
          check = false;
          break;
        }
        if (!check) {
          break;
        }
      }
    }

    if (check) {
      answer++;
    }
  }

  cout << answer * N << endl;

  return 0;
}