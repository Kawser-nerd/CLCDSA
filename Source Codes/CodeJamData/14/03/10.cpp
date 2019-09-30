#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

char board[100][100];

void print(int r, int c, bool swapped) {
  board[0][0] = 'c';
  if (swapped) {
    rep(i, c) {
      rep(j, r) {
	cout << board[j][i];
      }
      cout << endl;
    }
  } else {
    rep(i, r) {
      rep(j, c) {
	cout << board[i][j];
      }
      cout << endl;
    }
  }
}

void impossible() {
  cout << "Impossible" << endl;
}

void solve() {
  int r,c,m;
  bool swapped = false;
  cin >> r >> c >> m;
  int left = r * c - m;
  rep(i,100)rep(j,100) board[i][j] = '*';
  if (r > c) {
    swap(r,c);
    swapped = true;
  }

  if (left == 1) {
    print(r,c,swapped);
    return;
  }
  
  if (r == 1) {
    rep(i,left)board[0][i] = '.';
    print(r,c,swapped);
    return;
  }

  if (r == 2) {
    if (left % 2 == 1 || left == 2) {
      impossible();
      return;
    } else {
      rep(i, left / 2) {
	board[0][i] = '.';
	board[1][i] = '.';
      }
      print(r,c,swapped);
      return;
    }
  }

  if (left == 2 || left == 3 || left == 5 || left == 7) {
    impossible();
    return;
  } else {
    for (int i = 0; i < c; i++) {
      if (left == 3) break;
      if (left == 0) break;
      board[0][i] = '.';
      board[1][i] = '.';
      left -= 2;
    }
    if (left == 0) goto lbl;
    for (int i = 2; i < r; i++) {
      if (left == c + 1) {
	for (int j = 0; j < c - 1; j++) {
	  board[i][j] = '.';
	}
	board[i + 1][0] = '.';
	board[i + 1][1] = '.';
	goto lbl;
      }
      for (int j = 0; j < c; j++) {
	if (left == 0) goto lbl;
	board[i][j] = '.';
	left--;
      }
    }
  lbl:
    print(r,c,swapped);
    return;
  }
}

int main() {
  cout << setprecision(10);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i + 1 << ":" << endl;
    solve();
  }
  return 0;
}
