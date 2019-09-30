#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
  int t;
  scanf("%d", &t);
  for(int c = 1; c <= t; c++)
  {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > lawn(n, vector<int>(m));
    vector<int> max_row(n, 0);
    vector<int> max_col(m, 0);

    for(int _i = 0; _i < n; _i++)
      for(int _j = 0; _j < m; _j++) {
        scanf("%d", &(lawn[_i][_j]));
        max_row[_i] = max(max_row[_i], lawn[_i][_j]);
        max_col[_j] = max(max_col[_j], lawn[_i][_j]);
      }

    bool possible = true;
    for(int _i = 0; _i < n; _i++)
      for(int _j = 0; _j < m; _j++)
        possible = possible && lawn[_i][_j] >= min(max_row[_i], max_col[_j]);

    if (possible)
      printf("Case #%d: YES\n", c);
    else
      printf("Case #%d: NO\n", c);
  }
}
