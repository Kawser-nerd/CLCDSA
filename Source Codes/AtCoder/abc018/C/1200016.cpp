#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

vi dc = { 1,  0, -1,  0};
vi dr = { 0,  1,  0, -1};

int main() {
  int r, c, k;
  scanf("%d%d%d", &r, &c, &k);
  vvi board(r+2, vi(c+2, 0));
  rep (ir, r) {
    char tmp;
    rep (ic, c) {
      scanf(" %c", &tmp);
      if (tmp == 'x') board[ir+1][ic+1] = 1;
    }
  }

  rep (i_, k-1) {
    vvi board_next = board;
    FOR (ir, 1, r+1) {
      FOR (ic, 1, c+1) {
        if (board[ir][ic] == 1) continue;
        rep (i, 4) {
          if (board[ir + dr[i]][ic + dc[i]] == 1) {
            board_next[ir][ic] = 1;
            break;
          }
        }
      }
    }
    swap(board, board_next);
  }

  int ans = 0;
  FOR (ir, k, r - k + 2) {
    FOR (ic, k, c - k + 2) {
      ans += (1 - board[ir][ic]);
    }
  }
  printf("%d\n", ans);

  return 0;
}