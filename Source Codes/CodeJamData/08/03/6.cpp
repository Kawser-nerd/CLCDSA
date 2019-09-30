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

#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

#define N 3000


double f, R, t, r, g;
int n;
double x_left[N], x_right[N];

double area1( double x )
{
  //printf("%.5lf: %.5lf\n", x / R, asin(x / R));
  return (x * sqrt(R * R - x * x) + R * R * asin(x / R)) / 2;
}
bool betw( double a, double b, double c )
{
  return ((c >= a - EPS && c <= b + EPS) || (c >= b - EPS && c <= a + EPS));
}
double area2( double x_1, double x_2, double y_1, double y_2 )
{
  if (x_2 * x_2 + y_2 * y_2 <= R * R + EPS)
  {
   // printf("in\n");
    return (x_2 - x_1) * (y_2 - y_1);
  }
  if (x_1 * x_1 + y_1 * y_1 > R * R + EPS)
  {
   // printf("out\n");
    return 0;
  }
  
  double y_l, y_r;
  
  y_l = sqrt(R * R - x_1 * x_1);
  y_r = sqrt(R * R - x_2 * x_2);  
  
  if (betw(y_1, y_2, y_l) && betw(y_1, y_2, y_r))
  {
    //printf("1\n");
    return area1(x_2) - area1(x_1) - (x_2 - x_1) * y_1;
  }
  if (!betw(y_1, y_2, y_l) && betw(y_1, y_2, y_r))
  {
    //printf("2\n");    
    double x = sqrt(R * R - y_2 * y_2);
    return (x - x_1) * (y_2 - y_1) + (area1(x_2) - area1(x)) - (x_2 - x) * y_1;
  }
  if (betw(y_1, y_2, y_l) && !betw(y_1, y_2, y_r))
  {
    //printf("3\n");    
    double x = sqrt(R * R - y_1 * y_1);
    return area1(x) - area1(x_1) - (x - x_1) * y_1;
  }
  if (!betw(y_1, y_2, y_l) && !betw(y_1, y_2, y_r))
  {
    //printf("4\n");    
    double x_l, x_r;
    x_l = sqrt(R * R - y_2 * y_2);
    x_r = sqrt(R * R - y_1 * y_1);
    return (x_l - x_1) * (y_2 - y_1) + area1(x_r) - area1(x_l) - (x_r - x_l) * y_1;
  }
  
  printf("kosyak!\n");
  return 0;
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
    cin >> f >> R >> t >> r >> g;
    
    double denom = (PI * R * R) / 4;
    double num = 0;
    
    num += (PI * (R * R - (R - t - f) * (R - t - f))) / 4;
    //printf("init = %.3lf\n", num);
    
    if (f + f > g + EPS)
    {
      printf("Case #%i: %.9lf\n", test, 1.0);      
      continue;
    }   
    if (R - t - f < EPS)
    {
      printf("Case #%i: %.9lf\n", test, 1.0);      
      continue;      
    } 
    
    
    g += 2 * r;
    
    r += f;
    R -= t + f;
    
    n = 0;    
    double cur_x = 0;
    while (true)
    {
      double x_l, x_r;
      if (!n)
      {
        x_l = 0;
        x_r = x_l + r;
      }
      else
      {
        x_l = cur_x - r;
        x_r = cur_x + r;
      }   
      if (x_l >= R - EPS)
        break;
      x_r = min(x_r, R);
      
      //printf("[%.3lf, %.3lf]\n", x_l, x_r);
 
      x_left[n] = x_l;
      x_right[n] = x_r;
      n++;
      
      num += 2 * (area1(x_r) - area1(x_l));
   
      cur_x += g;        
    }
    
    //printf("n = %i\n", n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        num -= area2(x_left[i], x_right[i], x_left[j], x_right[j]);
            
    printf("Case #%i: %.9lf\n", test, num / denom);
  }  
  
  return 0;
}
