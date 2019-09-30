#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int rle_len(const string &orig, const vector<int> &perm)
{
  string s;
  int n = orig.length();
  int k = perm.size(), pi = 0, st = 0;
  for ( int i=0; i<n; ++i )
  {
    s.push_back(orig[st + perm[pi]]);
    ++pi;
    if ( pi == k )
    {
      pi = 0;
      st += k;
    }
  }
  int i = 0, c = s[0], np = 1;
  for ( int j=1; j<n; ++j )
    if ( s[j] != c )
    {
      np++;
      c = s[j];
    }
  return np;
}


int get_min(const string &s, int k)
{
  vector<int> perm(k);
  for ( int i=0; i<k; ++i )
    perm[i] = i;
  int best = s.length();
  do
  {
    best = min(best, rle_len(s, perm));
  } while ( next_permutation(perm.begin(), perm.end()) );
  return best;
}


int main()
{
  int N;
  cin >> N;
  for ( int nc=1; nc<=N; ++nc )
  {
    int k;
    string S;
    cin >> k;
    cin >> S;
    cout << "Case #" << nc << ": " << get_min(S, k) << endl;
  }
  return 0;
}
