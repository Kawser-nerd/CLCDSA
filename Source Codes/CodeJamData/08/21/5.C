#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector< pair<int, int> > gen_grid(int n, long long A, 
    long long B, long long C, long long D, int x0,
    int y0, int M)
{
  long long X = x0, Y = y0;
  vector< pair<int, int> > res;
  res.push_back(make_pair(X, Y));
  for ( int i=1; i<=n-1; ++i )
  {
    X = (A*X + B)%M;
    Y = (C*Y + D)%M;
    res.push_back(make_pair(X, Y));
  }
  return res;
}


int brute(vector< pair<int, int> > &grid)
{
  int N = grid.size();
  int r = 0;
  for ( int i=0; i<N; ++i )
    for ( int j=i + 1; j<N; ++j )
      for ( int k=j + 1; k<N; ++k )
      {
        int sx = grid[i].first + grid[j].first + grid[k].first;
        int sy = grid[i].second + grid[j].second + grid[k].second;
        if ( sx%3 != 0 or sy%3 != 0 )
          continue;
        ++r;
      }
  return r;
}


int main()
{
  int N;
  cin >> N;
  for ( int nc=1; nc<=N; ++nc )
  {
    int n, A, B, C, D, x0, y0, M;
    cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
    vector< pair<int, int> > g = gen_grid(n, A, B, C, D, x0, y0, M);
    cout << "Case #" << nc << ": " << brute(g) << endl;
  }
  return 0;
}
