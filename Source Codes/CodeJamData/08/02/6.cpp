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

#define DAY 1440

int n, m;
int t;
int a_in[DAY], b_in[DAY], a_out[DAY], b_out[DAY], ;

int time2int( string s )
{
  //cout << s << endl;
  return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
}

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
    stream >> t;
    
    getline(cin, s);
    stream.clear();
    stream.str(s);    
    stream >> n >> m;
    
    memset(a_in, 0, sizeof(a_in));
    memset(a_out, 0, sizeof(a_out));
    memset(b_in, 0, sizeof(b_in));
    memset(b_out, 0, sizeof(b_out));            
      
    for (int i = 0; i < n; i++)
    {
      getline(cin, s);
      int l, r;
      l = time2int(s.substr(0, 5));
      r = time2int(s.substr(6, 5));
      a_out[l]++;
      if (r + t < DAY)
        b_in[r + t]++;
      //printf("%i - %i\n", l, r);
    }
    for (int i = 0; i < m; i++)
    {
      getline(cin, s);
      int l, r;
      l = time2int(s.substr(0, 5));
      r = time2int(s.substr(6, 5)); 
      b_out[l]++;
      if (r + t < DAY)
        a_in[r + t]++;
      //printf("%i - %i\n", l, r);
    }
    
    int res_a, res_b;
    res_a = res_b = 0;
    
    int cur_a, cur_b;
    cur_a = cur_b = 0;
    for (int i = 0; i < DAY; i++)
    {
      // a
      cur_a += a_in[i];
      if (cur_a < a_out[i])
      {
        res_a += a_out[i] - cur_a;
        cur_a = 0;
      }
      else
        cur_a -= a_out[i];        
      
      // b
      cur_b += b_in[i];
      if (cur_b < b_out[i])
      {
        res_b += b_out[i] - cur_b;
        cur_b = 0;
      }
      else
        cur_b -= b_out[i];
    }  
        
    cout << "Case #" << test << ": " << res_a << " " << res_b << "\n";
  }  
  
  return 0;
}
