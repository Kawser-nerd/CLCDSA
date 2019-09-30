#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"
#define TASKMOD "small"
#define sz(x) ((int)((x).size()))

typedef long long ll;
typedef double ld;

const ld EPS = 1e-10;
int sgn(ld x) { return x < -EPS ? -1 : x > EPS; }


struct pt {
  ld x, y;
  pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
  bool operator<(const pt &p2) const {
    if (fabs(x - p2.x) > EPS) return x < p2.x;
    return y < p2.y - EPS;
  }
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  ld operator*(const pt &p2) const { return sgn(x * p2.y - y * p2.x); }
  ld dist2() const { return x * x + y * y; }
};

pt root;
bool rcmp(pt a, pt b) {
  a = a - root; b = b - root;
  int s = a * b;
  if (s) return s > 0;
  return a.dist2() < b.dist2() - EPS;
}
bool good(const pt &a, const pt &b, const pt &c) { return (b - a) * (c - a) > 0; }
vector<pt> convex(vector<pt> pts) {
  swap(*pts.begin(), *min_element(pts.begin(), pts.end()));
  root = pts[0];
  sort(pts.begin() + 1, pts.end(), rcmp);
  vector<pt> st(sz(pts)); int ste = 0;
  for (int i = 0; i < sz(pts); i++) {
    while (ste >= 2 && !good(st[ste - 2], st[ste - 1], pts[i]))
      ste--;
    st[ste++] = pts[i];
  }
  st.resize(ste);
  return st;
}

struct line {
  ld a, b, c;
  ld cang;

  line() {}
  line(ld a,ld b,ld c):a(a),b(b),c(c){
    norm();
  }
  line(const pt &p1, const pt &p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -a * p1.x - b * p1.y;
    norm();
  }
  void norm(){
    ld d = sqrt(a * a + b * b);
    a /= d;
    b /= d;
    c /= d;
    cang = atan2(b, a); 
  }
  int side(const pt &p) const {
    return sgn(a * p.x + b * p.y + c);
  }

  bool operator||(const line &l2) const { return sgn(a * l2.b - b * l2.a) == 0; }

  pt operator&(const line &l2) const {
//    eprintf("%lf %lf %lf\n%lf %lf %lf\n",a,b,c,l2.a,l2.b,l2.c);
    ld d = a * l2.b - b * l2.a;
    assert(fabs(d) > EPS);
    pt res(
      (b * l2.c - c * l2.b) / d,
      (a * l2.c - c * l2.a) / -d
    );
    return res;
  }
  bool angEq(const line &l2) const {
    ld d = fabs(cang - l2.cang);
    if (2 * M_PI - d < d) d = 2 * M_PI - d;
    return d < EPS;
  }
  bool operator<(const line &l2) const {
    ld d = fabs(cang - l2.cang);
    if (d < EPS) return c < l2.c - EPS;
    return cang < l2.cang;
  }
};

// BEGIN ALGO
bool cross(vector<line> all) {
  {
    const ld BBOXC = 5.5e10;
    vector<pt> bbox;
    bbox.pb(pt( BBOXC, -BBOXC));
    bbox.pb(pt( BBOXC,  BBOXC));
    bbox.pb(pt(-BBOXC,  BBOXC));
    bbox.pb(pt(-BBOXC, -BBOXC));
    bbox.pb(bbox[0]);
    for (int i = 0; i < 4; i++)
      all.pb(line(bbox[i], bbox[i + 1]));
  }
  
  sort(all.begin(), all.end());
  int off = 0;
  for (int i = 1; i < sz(all); i++)
    if (all[i - 1].angEq(all[i])) {
      off++;
    } else
      all[i - off] = all[i];
  all.resize(sz(all) - off);

//  for (int i = 0; i < sz(all); i++)
//    eprintf("%lf %lf %lf\n", (double)all[i].a,(double)all[i].b,(double)all[i].c);
//  eprintf("\n\n");
  
  vector<pt> pts;
  vector<line> ss;
  ss.pb(all[0]);
  int deleted = 0;
  
  for (int i = 1; i < sz(all); i++) {
    int pcnt = sz(pts);
    while (sz(pts) > deleted && /*BOXNEXT*/
           all[i].side(pts[sz(pts) - 1]) <= 0) {
      pts.erase(pts.end() - 1);
      ss.erase(ss.end() - 1);
    }
    if (sz(pts) == deleted && pcnt) {  /*BOXNEXT*/
      if (pt(ss[sz(ss) - 1].a, ss[sz(ss) - 1].b) * 
          pt(all[i].a, all[i].b) <= 0)
        return false;
    } else {
      while (sz(pts) > deleted && 
             all[i].side(pts[deleted]) <= 0)
          ++deleted;
    } /*BOXNEXT*/
    if ((ss[sz(ss) - 1] || all[i])) // parallel !!!
      return false;  /*BOXNEXT*/
    pt cpt = ss[sz(ss) - 1] & all[i]; // intersect
    if (ss[deleted].side(cpt) >= 0) {
      pts.pb(cpt);
      ss.pb(all[i]);
    }
  }
  return true;
}




void PreCalc(){
}

int n;
vector<int> t(n);


bool check(ld mid){
   vector<line> ls(2*n);
   for (int j = 0; j < n; j++){
       ls[2*j]   = line(-1, -j,  t[j]+mid);
       ls[2*j+1] = line( 1,  j, -t[j]+mid);
   }
   return cross(ls);
}

void solve(){
   scanf("%d",&n);
   t.resize(n);
   for (int i = 0; i < n; i++)
       scanf("%d",&t[i]);
//   check(0);
//   return;
   ld l = 0;
   ld r = 2e6;
   for (int i = 0; i < 120; i++){
       ld mid = (l + r) / 2.0;
       if (check(mid)) r = mid;
       else l = mid;
   }

   cout.precision(15);
   cout << fixed << (l + r) / 2 << endl;    
}


int main(){
  freopen(TASKNAME"-"TASKMOD".in","r",stdin);
  freopen(TASKNAME"-"TASKMOD".out","w",stdout);
    
  PreCalc();
  TIMESTAMP(PreCalc);   

  char buf[1000];
  int testNum;
  gets(buf);
  sscanf(buf,"%d",&testNum);

  for (int testId = 1; testId <= testNum; testId++){
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0){
        TIMESTAMPf("Test %d",testId);
    }
    printf("Case #%d: ",testId);
    solve();                        
  }
      
  TIMESTAMP(end);
  return 0;
}