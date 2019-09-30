#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

struct letter_set
{
  letter_set()
  {
    memset(buf, 0, sizeof(buf));
  }
  letter_set(char x)
  {
    memset(buf, 0, sizeof(buf));
    add(x);
  }
  void add(char x)
  {
    buf[x - 'a'] = true;
  }
  bool exists(char x) const
  {
    return buf[x - 'a'];
  }
  enum { N = 'z' - 'a' + 1 };
  bool buf[N];
};


void compile(string const &pattern, vector<letter_set> &cp)
{
  cp.clear();
  bool inside = false;
  for ( size_t i=0; i<pattern.length(); ++i )
  {
    char x = pattern[i];
    if ( x == '(' )
    {
      inside = true; 
      cp.push_back(letter_set());
      continue;
    }
    if ( x == ')' )
    {
      inside = false; continue;
    }
    if ( inside )
    {
      cp[cp.size() - 1].add(x);
      continue;
    }
    cp.push_back(letter_set(x));
  }
}


bool matches(string const &word, vector<letter_set> const &cp)
{
  if ( word.length() != cp.size() )
    return false;
  for ( size_t i=0; i<word.length(); ++i )
    if ( not cp[i].exists(word[i]) )
      return false;
  return true;
}


int main()
{
  int L, D, N;
  cin >> L >> D >> N;
  vector<string> W;
  for ( int l=0; l<D; ++l )
  {
    string w;
    cin >> w;
    W.push_back(w);
  }
  vector<letter_set> cp;
  for ( int n=1; n<=N; ++n )
  {
    string pat;
    cin >> pat;
    compile(pat, cp);
    int cnt = 0;
    for ( int l=0; l<D; ++l )
      if ( matches(W[l], cp) )
        ++cnt;
    cout << "Case #" << n << ": " << cnt << endl;
  }
  return 0;
}
