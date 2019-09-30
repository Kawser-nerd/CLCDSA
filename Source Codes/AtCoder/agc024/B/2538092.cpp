#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
 
typedef vector<string> vs;
typedef vector<vs> vvs;
 
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
 
typedef map<string, int> msi;
 
typedef pair<int, int> pii;
typedef pair <ll, ll> pll; // note 'single' ls
 
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)
 
#define pb \
push_back
 
#define ff \
first
 
#define ss \
second

int main()
{
  int n;
  cin >> n;

  int out_of_order = 0;

  vi P;
  vi P_inv(n+1);

  REP(i, 1, n)
  {
    int p;
    cin >> p;

    P.pb(p);
    P_inv[p]=i;
  }

  if (n==1)
  {
    cout << 0 << endl;
    return 0;
  }

  // if (n==2)
  // {
  //   if (P[0] == 1) cout << 0 << endl;
  //   else cout << 1 << endl;

  //   return 0;
  // }

  // find longest contiguous section of non-flips ...

  vb not_flips;

  REP(i, 1, n-1)
  {
    not_flips.pb(P_inv[i]<P_inv[i+1]);
  }

  // for (auto f:not_flips)
  // {
  //   cout << f << endl;
  // }
  // cout << endl;

  vi flip_lengths;
  flip_lengths.pb(int(not_flips[0]));
  
  REP(i, 1, n-2)
  {
    if (not_flips[i]) flip_lengths.pb(flip_lengths.back()+1);
    else flip_lengths.pb(0);
  }

  // for (auto f:flip_lengths)
  // {
  //   cout << f << endl;
  // }
  // cout << endl;

  int max_f_length = 0;

  for (auto l:flip_lengths)
  {
    if (l > max_f_length)
    {
      max_f_length = l;
    }
  }

  cout << n - 1 - max_f_length << endl;

  return 0;
}