#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n;i>=0;i--)
using namespace std;

int main() {
  char board[4][4];
  REP(i,4)
    REP(j,4)
      cin >> board[i][j];

  REPD(i,3)
    REPD(j,3)
      cout << board[i][j] << (j==0 ? '\n':' ');
}