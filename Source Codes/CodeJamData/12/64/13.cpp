#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//#include <iostream>
//#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

#define LS <
#define Size(x) (int(x.size()))
#define LET(k,val) typeof(val) k = (val)
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))

#define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)

#define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
#define LAST(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
#define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k LS (b); ++k) {act;}, R##k)
#define SUMTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k += (x))
#define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
#define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
#define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
#define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
#define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
#define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make_pair(x,k)).second)

int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

int cnum, Tests, err;

//Eryx
// (th

/// ----

#define BUFSIZE 1000000
char buf[BUFSIZE];

#ifdef DEBUG
#define DEB(x) x
#else
#define DEB(x)
#endif

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int getNum() {
  string s = getLine();
  return atoi(s.c_str());
  }

vi parsevi(string s) {
  s = s + " ";
  int q = 0;
  bool minus = false;
  vi res;
  FOR(l,0, Size(s)) {
    if(s[l] == ' ') { res.push_back(minus?-q:q); q = 0; minus = false;}
    else if(s[l] == '-') { minus = true; }
    else { q = q * 10 + s[l] - '0'; }
    }
  return res;
  }

int N, M;
struct point {
  int x, y, cat;
  int prev, next;
  ld ro;
  int oi;
  };
 
bool gotzero = false;

int ox[9000], oy[9000], cx, cy;

point mpoint(int oi, int x, int y, int Cx, int Cy, int cat) { point p; p.x=x; p.y=y; p.cat=cat; 
  p.ro = atan2(x-Cx, y-Cy); p.oi = oi;
  return p;  
}

vector<point> pts;

bool ptscomp(const point& a, const point& b) {
  return a.ro < b.ro;
}

void solve2();

void solveCase() {
  int res = 0;
  // proceed
  err=scanf("%d%d", &N, &M);
  FOR(n,0,N) err=scanf("%d%d", &ox[n], &oy[n]);
  solve2();
}

ld bsc[4];

vector<int> pv;
 
bool pvsort(int a, int b) {
  ld aa = atan2(ox[a]*ll(N)-cx, oy[a]*ll(N)-cy);
  ld bb = atan2(ox[b]*ll(N)-cx, oy[b]*ll(N)-cy);
  return aa < bb;
}

bool badangle(int p1, int p2, int p3) {
  int dx2 = ox[p2] - ox[p1];
  int dy2 = oy[p2] - oy[p1];
  
  int dx3 = ox[p3] - ox[p1];
  int dy3 = oy[p3] - oy[p1];

  int cros =dx2*dy3 - dy2*dx3; 
//  printf("[%d %d %d] %d\n", p1,p2,p3, cros); 
  
  return cros >= 0;
}

void chull() {
  pv.clear();
  FOR(n,0,N) if(ox[n]*N!=cx || oy[n]*N!=cy) pv.push_back(n);
  sort(pv.begin(), pv.end(), pvsort);

/*      printf("CH: "); FOR(n,0,Size(pv)) printf("%d ", pv[n]);
   printf("\n");  */

   for(int aa=0; aa<Size(pv); aa++) if(aa>=0)
    if(badangle(pv[aa], pv[(aa+1)%Size(pv)], pv[(aa+2)%Size(pv)])) {
      int ctv = (aa+1) % Size(pv);
      FOR(u,ctv,Size(pv)-1) pv[u] = pv[u+1];
      pv.resize(Size(pv)-1);
      aa -= 2;      
    }
   if(0) {printf("CH: "); FOR(n,0,Size(pv)) printf("%d ", pv[n]);
   printf("\n"); }
  }

int valof(int id) {
  return ox[id] * 2003 + oy[id];
}

void solve2() {
  cx=0; cy=0;
  FOR(n,0,N) cx += ox[n], cy += oy[n];
  
  chull();
  
  if(Size(pv) < 3) {
    pv.clear();
    int minv = 0, maxv = 0;
    FOR(n,0,N) {
        if(valof(n) < valof(minv)) minv = n;
	if(valof(n) > valof(maxv)) maxv = n;
    }
    pv.push_back(minv); pv.push_back(maxv);
    //printf("minv=%d maxv=%d\n", minv, maxv);
    }
  
  FOR(tr,3,4) {
  pts.clear();
  //cx=0;cy=0;
  int PP = Size(pv);
  
  FOR(n,0,PP) {  
    int x=ox[pv[n]], y=oy[pv[n]];
    if(1) {
    int nx = ox[pv[(n+1)%PP]], ny = oy[pv[(n+1)%PP]];
    
    pts.push_back(mpoint(pv[n],+x, +y, +nx, +ny, 0));
    pts.push_back(mpoint(pv[n],-y, +x, -ny, +nx, (tr&1)?1:3));
    pts.push_back(mpoint(pv[n],-x, -y, -nx, -ny, 2));
    pts.push_back(mpoint(pv[n],+y, -x, +ny, -nx, (tr&1)?3:1)); }
  }
  sort(pts.begin(), pts.end(), ptscomp);
  
  
  ld bestscore = 0;
  
  int lid[4];
  FOR(xx,0,4) lid[xx] = 0;
  int P = Size(pts);
  FOR(u,0,2) FOR(p,0,P) {
    pts[p].prev = lid[pts[p].cat];
    lid[pts[p].cat] = p;
    }
  FOR(p,0,P) pts[pts[p].prev].next = p;
  
  if(0) FOR(p,0,P) {
     printf("%3d. %d.%d -> %d\n", p, pts[p].oi, pts[p].cat, pts[p].next);
  }
  
  FOR(p,0,P) {
    FOR(m,0,16) FOR(drop,0,4) {
      if(drop > M) continue;
      // if(drop) continue; // erase!
      ll totx=0, toty=0;
      int sm = m;
      FOR(ca,0,4) {
	int cx = sm%2; sm /= 2;
	ll mul = (M+(tr>=2?3-ca:ca)-drop)/4;
	// if(mul!=1) printf("ERRMUL\n");
	//printf("%d: M=%lld\n", ca, mul);
	int lc = lid[ca];
	int nc = pts[lc].next;
	int cc = cx ? nc : lc;
	// cc = lc; FOR(uu,0,cx) cc = pts[cc].next;
	totx += mul * pts[cc].x, toty += mul * pts[cc].y;
	//if(mul) printf("%d ", pts[cc].oi);
      }
      // printf("totx=%4lld toty=%4lld ", totx, toty);
      ld cscore = sqrt(totx*(1.0*totx) + toty*(1.0*toty));
      //printf("%Lf\n", cscore);
      if(cscore > bestscore) bestscore = cscore;
    }
    lid[pts[p].cat] = p;  
  }
  
  
  
  printf("Case #%d: %.8Lf\n", cnum+1, bestscore * sqrt(2)); 
  bsc[tr] = bestscore;    
  //if(tr == 3 && bsc[3] != bsc[0]) printf("Case #%d: %.8Lf\n", cnum+1, bestscore * sqrt(2)); 
  }
  if(0) {
     // 
     ld best = 0;
     int bestat, bestatmu;
     if(0) printf("N=%d M=%d cnum=%d\n", N, M, cnum);
     if(M>8) return;
     
     FOR(MU,0,M+1) {
     ll pow = 1;
     FOR(m,0,MU) pow *= N;
     
     FOR(tr,0,pow) {
       int str = tr;
       int cx=0, cy=0;
       FOR(tt,0,MU) {
	 int cs = str%N; str /= N;
	 //printf("%d ", cs);
	 
	 int ncx = ox[cs] - oy[cs] + cy;
	 int ncy = ox[cs] + oy[cs] - cx;
	 cx = ncx; cy = ncy;
       }
       {ld cur = sqrt(cx*cx+cy*cy); // printf("%Lf\n", cur / sqrt(2));
       if(cur >best) {best = cur; bestat=tr; bestatmu = MU;} }
       nexttr: ;
     }
     }
     
     if(fabs(best / sqrt(2) - bsc[3]) > .001) {
       printf("true = %.8Lf (%.8Lf)\n", best / sqrt(2), bsc[3]);
       printf("%.8Lf %.8Lf %.8Lf %.8Lf\n", bsc[0], bsc[1], bsc[2], bsc[3]);
printf("N=%d M=%d\n", N, M);
             FOR(n,0,N) printf("%d %d\n", ox[n], oy[n]);
      printf("bestat=%d bestatmu=%d\n", bestat, bestatmu);
      exit(1);
     }
     
  }
  }

int main() {
  N = 4; M = 3;
  if(0) {
    
    if(0) FOR(u,0,5000) {
    FOR(a,0,N) ox[a] = rand() % 4, oy[a] = rand() % 4;
    solve2();
  }
   
  exit(1);
  }
  if(0) Tests = 1;
  else if(0) {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  else {
    err = scanf("%d", &Tests);
    }

  for(cnum=0; cnum<Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// I also have a preprocessor which turns this solution into one that
// runs test cases in separate processes in order to make it faster
