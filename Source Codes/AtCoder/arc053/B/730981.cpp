#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define debug(x) cout<< #x <<": "<<x<<endl
#define debug2(x,y) cout<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < s.length(); ++i) {
    mp[s[i]] += 1;
  }
  int pairs = 0;
  int seperates = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    pairs += mp[c]/2;
    seperates += mp[c]%2;
  }
  if (seperates == 0) {
    printf("%d\n", pairs*2);
    return 0;
  }
  printf("%d\n", (pairs/seperates)*2+1);

  return 0;
}