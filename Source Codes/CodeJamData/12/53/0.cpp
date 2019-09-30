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
typedef vector<string> vs;

#define LS <
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

int N;
ll Cash, Fee;

ll price[256], stale[256];

bool mode;

ll liveforcash(ll cash, ll &cashleft, ll &nextprice) {
  ll cf = 0;
  ll day = 0;
  while(true) {
  
    if(cf >= N) {
      cashleft = 0; 
      nextprice = -1;
      return day;
      }
    else if(stale[cf] < day) cf++;
    else if(price[cf] > cash) { 
      cashleft = cash; nextprice = price[cf]; 
      return day; }
    else if(mode == 1) {
      day++; cash -= price[cf];
      }
    else {

      ll ds = min(cash / price[cf], stale[cf] - day + 1);
    
      day += ds; cash -= ds * price[cf];
      }
    }
  }

ll solvefor(ll del) {
    ll xdays = 0;
    ll mcash = Cash - Fee * del;

    ll ccash = mcash / del;
    ll cashleft, nextprice=1;
    
    mode = 0;
    ll cdays = liveforcash(ccash, cashleft, nextprice);
    
    if(0) {
      mode = 1;
      ll cdays0 = liveforcash(ccash, cashleft, nextprice);
      if(cdays0 != cdays) { printf("err\n"); exit(1); }
      }
      
    xdays = del * cdays;
    if(nextprice > 0) xdays += (cashleft * del + mcash%del) / nextprice;
    
  return xdays;

    if(0) if(del<1000) {
      ll ydays = xdays, mmcash = mcash;
      ll xdays = 0;
      ll mcash = Cash - Fee * del;
  
      FOR(z,0,del) {
        ll ccash = mcash / (del-z);
        ll cashleft, nextprice=0;
      
        ll cdays = liveforcash(ccash, cashleft, nextprice);
        xdays += cdays;
        mcash -= ccash; mcash += cashleft;
        }
  
      if(xdays !=  ydays) {
        exit(1);
        }
      }
  }

void solveCase() {
  // proceed
  
  err=scanf("%lld%lld%d", &Cash, &Fee, &N);
  
  FOR(a,0,N) err=scanf("%lld%lld", &price[a], &stale[a]);
  
  FOR(a,0,N) if(a>0 && price[a] < price[a-1]) swap(price[a], price[a-1]), swap(stale[a], stale[a-1]), a-=2;
  
  if(0) { FOR(a,0,N) price[a] *= 1000000; Fee *= 1000000; Cash *= 1000000; }
  
  ll best = 0;
  
  // fprintf(stderr, "Cash=%lld fee=%lld CF=%d\n", Cash, Fee, N);
  
  // if(Cash > 5000 && Fee == 1) return;
  
  ll mindel = 1;
  ll maxdel = Cash / Fee;
  
  while(maxdel > mindel + 10) {
    ll part1 = (mindel*2+maxdel) / 3;
    ll part2 = (mindel+2*maxdel) / 3;
    
    ll s1 = solvefor(part1);
    ll s2 = solvefor(part2);
    
    if(s1 < s2) mindel = part1;
    else maxdel = part2;
    }
  
  for(ll del=mindel; del<=maxdel; del++) {
  
    ll xdays = solvefor(del);
    
    /* if(xdays < best && xdays > ldays) {
      printf("not unimodal\n"); exit(1);
      } */
      
    if(xdays > best) best = xdays;
    // ldays = xdays;
    
    }
  
  printf("Case #%d: %lld\n", cnum+1, best);
  fflush(stdout);
  }

int main() {
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
