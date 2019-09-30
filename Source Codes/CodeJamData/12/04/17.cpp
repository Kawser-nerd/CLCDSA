#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORZ(i,b) FOR(i,0,(b))
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

enum { MAX = 200 };
int board[MAX][MAX];
int W, H;

bool inBounds(int x, int y) {
  return x >= 0 && x < W && y >= 0 && y < H;
}

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

bool hits(int xl, int yl, int xs, int ys) {
  int xdir = (xl > 0 ? 1 : xl < 0 ? -1 : 0);
  int ydir = (yl > 0 ? 1 : yl < 0 ? -1: 0);
  xl *= xdir;
  yl *= ydir;
  int xt, yt, xT, yT;
  if (xdir == 0 && ydir == 0) {
    return false;
  }
  if (xdir == 0 || ydir == 0) {
    xt = yt = xT = yT = 1;
  } else {
    xt = xT = yl;
    yt = yT = xl;
  }
  int xc = 0, yc = 0, x, y;
  x = xs = 2 * xs + 1;
  y = ys = 2 * ys + 1;
  xl *= 2;
  yl *= 2;
  while (xc < xl || yc < yl) {
    if (xT == yT) {
      xc++;
      yc++;
      x += xdir;
      y += ydir;
      xT += xt;
      yT += yt;
      if (x == xs && y == ys) {
        return true;
      }
      if (x % 2 == 0 && y % 2 == 0) {
        int xCoord = (x + xdir)/2;
        int yCoord = (y + ydir)/2;
        assert(inBounds(xCoord, yCoord));
        if (board[xCoord][yCoord]) {
          if (board[xCoord - xdir][yCoord] && board[xCoord][yCoord - ydir]) {
            xdir *= -1;
            ydir *= -1;
          } else if (board[xCoord - xdir][yCoord]) {
            ydir *= -1;
          } else if (board[xCoord][yCoord - ydir]) {
            xdir *= -1;
          } else {
            return false;
          }
        }
      } else if (x % 2 == 0) {
        int xCoord = (x + xdir)/2;
        int yCoord = y/2;
        assert(inBounds(xCoord, yCoord));
        if (board[xCoord][yCoord]) {
          xdir *= -1;
        }
      } else if (y % 2 == 0) {
        int yCoord = (y + ydir)/2;
        int xCoord = x/2;
        if (board[xCoord][yCoord]) {
          ydir *= -1;
        }
      }
    } else if (xT < yT) {
      xc++;
      x += xdir;
      xT += xt;
      if (x % 2 == 0) {
        int xCoord = (x + xdir)/2;
        int yCoord = (2*y + ydir)/4;
        assert(inBounds(xCoord, yCoord));
        if (board[xCoord][yCoord]) {
          xdir *= -1;
        }
      }
    } else {
      yc++;
      y += ydir;
      yT += yt;
      if (y % 2 == 0) {
        int yCoord = (y + ydir)/2;
        int xCoord = (2*x + xdir)/4;
        assert(inBounds(xCoord, yCoord));
        if (board[xCoord][yCoord]) {
          ydir *= -1;
        }
      }
    }
  }
  return false;
}

int main() {
  int tt;
  cin >> tt;
  FOR(t,1,tt+1) {
    printf("Case #%d: ", t);
    int D;
    scanf("%d %d %d", &H, &W, &D);
    getchar();
    int xs, ys;
    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        int c = getchar();
        if (c == 'X') {
          xs = x;
          ys = y;
        }
        board[x][y] = (c == '#');
      }
      getchar();
    }
    int count = 0;
    int D2 = D*D;
    for (int xl = -D; xl <= D; ++xl) {
      for (int yl = -D; yl <= D; ++yl) {
        if (gcd(abs(xl), abs(yl)) != 1) continue;
        if (xl*xl + yl*yl > D2) continue;
        int xl2 = xl, yl2 = yl;
        while (xl2*xl2 + yl2*yl2 <= D2) {
          xl2 += xl;
          yl2 += yl;
        }
        xl2 -= xl;
        yl2 -= yl;
        if (hits(xl2, yl2, xs, ys)) {
          //fprintf(stderr,"(%d,%d)\n", xl2, yl2);
          count++;
        }
      }
    }
    printf("%d\n", count);
  }
  return 0;
}