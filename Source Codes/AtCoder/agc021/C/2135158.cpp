/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-25 16:28:33
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int X, Y, A, B;
char F[1020][1020];

void flush()
{
  for (auto i = 0; i < X; i++)
  {
    for (auto j = 0; j < Y; j++)
    {
      cout << F[i][j];
    }
    cout << endl;
  }
}

void standard_make()
{
  for (auto i = 0; i + 1 < X; i += 2)
  {
    for (auto j = 0; j + 1 < Y; j += 2)
    {
      if (A > 0)
      {
        F[i][j] = '<';
        F[i][j + 1] = '>';
        A--;
        if (A > 0)
        {
          F[i + 1][j] = '<';
          F[i + 1][j + 1] = '>';
          A--;
        }
      }
      else if (B > 0)
      {
        F[i][j] = '^';
        F[i + 1][j] = 'v';
        B--;
        if (B > 0)
        {
          F[i][j + 1] = '^';
          F[i + 1][j + 1] = 'v';
          B--;
        }
      }
    }
  }
}

void make()
{
  if (X % 2 == 1)
  {
    for (auto j = 0; j + 1 < Y; j += 2)
    {
      if (A > 0)
      {
        F[X-1][j] = '<';
        F[X-1][j + 1] = '>';
        A--;
      }
    }
  }
  if (Y%2 == 1)
  {
    for (auto i = 0; i + 1 < X; i += 2)
    {
    if (B > 0)
      {
        F[i][Y - 1] = '^';
        F[i + 1][Y - 1] = 'v';
        B--;
      }
    }
  }
  standard_make();
  flush();
}

void make2()
{
  if (X%2 == 1)
  {
    for (auto j = 0; j + 1 < Y - 2; j += 2)
    {
      if (A > 0)
      {
        F[X-1][j] = '<';
        F[X-1][j + 1] = '>';
        A--;
      }
    }
  }
  if (Y%2 == 1)
  {
    for (auto i = 0; i + 1 < X - 2; i += 2)
    {
    if (B > 0)
      {
        F[i][Y - 1] = '^';
        F[i + 1][Y - 1] = 'v';
        B--;
      }
    }
  }
  if (B > 0)
  {
    F[X - 3][Y - 3] = '^';
    F[X - 2][Y - 3] = 'v';
    B--;
  }
  if (B > 0)
  {
    F[X - 2][Y - 1] = '^';
    F[X - 1][Y - 1] = 'v';
    B--;
  }
  if (A > 0)
  {
    F[X - 3][Y - 2] = '<';
    F[X - 3][Y - 1] = '>';
    A--;
  }
  if (A > 0)
  {
    F[X - 1][Y - 3] = '<';
    F[X - 1][Y - 2] = '>';
    A--;
  }
  standard_make();
  flush();
}

int main()
{
  fill(&F[0][0], &F[0][0] + 1020 * 1020, '.');
  cin >> X >> Y >> A >> B;
  int S = (X * Y) / 2;
  int SA = X * (Y / 2);
  int SB = (X / 2) * Y;
  if (!(A+B <= S && A <= SA && B <= SB))
  {
    cout << "NO" << endl;
    return 0;
  }
  if (A+B == S && (SA - A) % 2 == 1)
  {
    if ((X * Y) % 2 == 0)
    {
      cout << "NO" << endl;
      return 0;
    } else {
      cout << "YES" << endl;
      make2();
      return 0;
    }
  }
  cout << "YES" << endl;
  make();
}