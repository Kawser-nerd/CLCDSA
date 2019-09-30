#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define eps 1e-9

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define sz(v)((v).size())

#define task_name "a"


using namespace std;

int get( vector < pair <int, int> > v, int all )
{
  sort(v.begin(), v.end());

  vector < pair <int, int> > t;
  for (int i = 0; i < (int)v.size(); i++)
    t.push_back(make_pair(v[i].second, i));

  sort(t.begin(), t.end());

  set <int> curr, bad;
  
  int j = (int)v.size() - 1;

  int res = 0;
  for (int i = 0; i < (int)v.size(); i++)
  {
    if (v[i].first <= all && !bad.count(i))
      curr.insert(i);
    while(j >= 0 && t[j].first > all - v[i].first)
      curr.erase(t[j].second), bad.insert(t[j].second), j--;
    res >?= (int)curr.size();
  }
  return res;
}


int main( void )
{
  freopen(task_name ".in", "r", stdin);
  freopen(task_name ".out", "w", stdout);

  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "tt = %d\n", tt);
    printf("Case #%d: ", tt);


    int n;
    cin >> n;

    vector < pair <int, pair<int, int> > > v; 

    for (int i = 0; i < n; i++)
    {
      int a, b, c;
      cin >> a >> b >> c;
      v.push_back(make_pair(a, make_pair(b, c)));
    }
    sort(v.begin(), v.end());
    int all = 10000;

    vector < pair <int, int> > curr;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
      curr.push_back(v[i].second);
      res >?= get(curr, all - v[i].first);
    }
    printf("%d\n", res);
  }

   
  
  return 0;
}