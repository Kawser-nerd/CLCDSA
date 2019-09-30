#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

stringstream stream("");

int tests;
string s;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

#define inf (int)1e9

#define N 200
#define M 2000

int n, m;
string a[N], b[M];
int t[M][N];

int main()
{
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  
  getline(cin, s);
  stream << s;
  stream >> tests;
  for (int test = 1; test <= tests; test++)
  {
    getline(cin, s);
    stream.clear();
    stream.str(s);
    stream >> n;
    for (int i = 1; i <= n; i++)
      getline(cin, a[i]);
    getline(cin, s);
    stream.clear();
    stream.str(s);
    stream >> m; 
    for (int i = 1; i <= m; i++)
      getline(cin, b[i]);
      
    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++)
        t[i][j] = inf;      
    for (int i = 1; i <= n; i++)
      t[0][i] = 0;
      
    for (int i = 0; i < m; i++)
      for (int j = 1; j <= n; j++)
      {
        for (int k = 1; k <= n; k++)
          if (k != j && a[k] != b[i + 1])
            t[i + 1][k] = min(t[i + 1][k], t[i][j] + 1);        
        if (a[j] != b[i + 1])
          t[i + 1][j] = min(t[i + 1][j], t[i][j]);
      }
    
    int ans = inf;
    for (int i = 1; i <= n; i++)
      ans = min(ans, t[m][i]);
    cout << "Case #" << test << ": " << ans << "\n";
  }  
  
  return 0;
}
