#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define Size(x) (int(x.size()))

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c <= 0) continue;
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int scanerr;

int getNum() {
#ifdef LINEBYLINE
  string s = getLine();
  return atoi(s.c_str());
#else
  int i;
  scanerr = scanf("%d", &i);
  return i;
#endif
  }

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

ll sdiv(ll a, ll b) {
  return (a+b-1) / b;
  }

ll IMPOSSIBLE;

ll nodebuff_brute(int aturns, int Hd, int lHd, int Ak) {
  int tspent = 0;
  while(aturns > 1 && tspent < 500) {
    if(lHd > Ak) lHd -= Ak, aturns--, tspent++;
    else lHd = Hd-Ak, tspent++;
    }
  if(tspent == 500) return IMPOSSIBLE;
  return tspent + 1;
  }

ll nodebuff_good(ll aturns, ll Hd, ll lHd, ll Ak) {
  // printf("-- aturns=%d Hd=%d/%d Ak=%d\n", aturns, lHd, Hd, Ak);
  if(Ak == 0) return aturns;
  if(lHd - (aturns-1) * Ak > 0) return aturns;
  ll oturns = aturns;
  int heals = 0;
  ll maxhits = (lHd-1) / Ak;
  if(maxhits >= aturns) return aturns;
  aturns -= maxhits;
  heals = 1; Hd = Hd - Ak; 
  if(Hd <= 0) return IMPOSSIBLE;
  // printf("   aturns=%d Hd=%d Ak=%d\n", aturns, 
  if(aturns == 1) return aturns+heals;
  ll healeach = sdiv(Hd, Ak);
  if(healeach == 1) return IMPOSSIBLE;
  if(healeach == 2) return oturns + 1 + (aturns-2) / (2-1);
  return oturns + 1 + (aturns-2) / (healeach-1);
  }

ll nodebuff_cmp(int aturns, int Hd, int lHd, int Ak) {
  ll brut = nodebuff_brute(aturns, Hd, lHd, Ak);
  ll good = nodebuff_good(aturns, Hd, lHd, Ak);
  if(brut != good)
     printf("-- aturns=%d Hd=%d/%d Ak=%d [brut=%Ld good=%Ld]\n", aturns, lHd, Hd, Ak, brut, good);
  return brut;
  }

#define nodebuff nodebuff_good

void solveCase() {
  IMPOSSIBLE = 1000000;
  IMPOSSIBLE *= 1000000;
  IMPOSSIBLE *= 1000000;
  int res = 0;

  ll Hd = getNum(), Ad = getNum(), Hk = getNum(), Ak = getNum(),
    B = getNum(), D = getNum();
  
  // proceed
  
  int aturns = 0;
  while(sdiv(Hk, Ad) >= 1 + sdiv(Hk, Ad+B)) {
    // printf("sdiv = %Ld\n", sdiv(Hk, Ad));
    aturns++, Ad += B;
    }
  
  aturns += sdiv(Hk, Ad);
  
  ll score = nodebuff(aturns, Hd, Hd, Ak);
  
  ll dbturns = 0;
  
  ll lHd = Hd;
  
  ll quickhits = Hd/Ak;
  ld thenhits = (Hd-Ak)/Ak;
  
  while(D > 0 && Ak > 0) {
    // printf("lHd=%Ld/%Ld D=%Ld Ak=%Ld\n", lHd, Hd, D, Ak);
    if(lHd <= Ak-D && Hd-Ak <= Ak-D) {
      // impossible
      break;
      }
    else if(lHd <= Ak-D) {
      // heal
      lHd = Hd - Ak;
      dbturns++;
      continue;
      }
    else {
      ll oAk = Ak;
      Ak = Ak - D;
      if(Ak < 0) Ak = 0;
      lHd = lHd - Ak;
      dbturns++;
      if(Ak && Hd / Ak == Hd/oAk) continue;
      }
    
    ll nscore = dbturns + nodebuff(aturns, Hd, lHd, Ak);
    if(nscore < score) score = nscore;
    }
  
  if(score >= IMPOSSIBLE)
    printf("Case #%d: IMPOSSIBLE\n", cnum);
  else
    printf("Case #%d: %Ld\n", cnum, score);
  }

#define P 1000000007

int main() {

  if(!MANYTESTS) Tests = 1;
  else Tests = getNum();
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
