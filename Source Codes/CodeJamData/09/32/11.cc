#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <cmath>
#include <set>

using namespace std;

typedef long long LL;
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<long long> Vll;
typedef vector<double> Vd;
typedef vector<Vi> Mi;
#define forUp(x,y) for(int x=0;x<(y);x++)
#define forDown(x,y) for(int x=(y)-1;x>=0;x--)
#define LET(l,r) forUp(_t,1) for(typeof(r) l=r; !_t; _t=1)
#define forEach(x,c) LET(&_s,(c)) LET(_x,_s.begin()) for(;_x!=_s.end();_x++) LET(&x,*_x)

struct Point3 {
  Point3() : x(0), y(0), z(0) {}
  Point3(double x, double y, double z) : x(x), y(y), z(z) {}
  
  double x,y,z;
};
Point3 operator+(const Point3& p1, const Point3& p2) { return Point3(p1.x+p2.x, p1.y+p2.y,p1.z+p2.z); }
Point3 operator/(const Point3& p, double d) { return Point3(p.x/d, p.y/d,p.z/d); }
Point3 operator*(double d, const Point3& p) { return Point3(p.x*d, p.y*d,p.z*d); }
Point3 operator-(const Point3& p) { return Point3(-p.x,-p.y,-p.z); }
double operator*(const Point3& a, const Point3& b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
double norm(const Point3& v) { return sqrt(v.x*v.x+v.y*v.y+v.z*v.z); }

int main() {
  int T; cin >> T;
  string s;
  getline(cin,s);
  forUp(t,T) {
    int N; cin >> N;
    Point3 pm,vm;

    forUp(i,N) {
      Point3 p,v;
      cin >> p.x >> p.y >> p.z;
      cin >> v.x >> v.y >> v.z;
      pm=pm+p; vm=vm+v;
    }
    pm=pm/N; vm=vm/N;

    double tmin=max(0.0,-(pm*vm)/(vm*vm));
    double dmin=norm(pm+tmin*vm);

    printf("Case #%d: %.8f %.8f\n",t+1,dmin,tmin); 
  }

  return 0;
}






