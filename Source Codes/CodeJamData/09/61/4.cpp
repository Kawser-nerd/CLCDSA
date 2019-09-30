#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

class Natural {
  static const int BASE = 1000000000;
  static const int BASEDIGS = 9;
  int ndigs;
  int *digs;
  void init(int n,const int *d) {
    while(n>0 && d[n-1]==0) --n;
    ndigs=n;
    digs=new int[n];
    for(int i=0;i<n;++i) digs[i]=d[i];
  }
  Natural(int n,const int *d) { init(n,d); }
  /* przesuwanie (dla dzielenia i pierwiastkowania) */
  Natural operator<<(int sh) const { // sh >= 0
    int n=sh+ndigs;
    int d[n];
    REP(i,sh) d[i]=0;
    REP(i,ndigs) d[i+sh]=digs[i];
    return Natural(n,d);
  }
public:
  /* konstruktory */
  Natural(int x=0) {
    int d[2];
    d[0]=x%BASE;
    d[1]=x/BASE;
    init(2,d);
  }
  Natural(const Natural&a) {
    init(a.ndigs,a.digs);
  }
  Natural(const char *s) {
    int n=strlen(s);
    int nd=n/BASEDIGS+1;
    int d[nd];
    REP(i,nd) {
      d[i]=0;
      FORD(j,BASEDIGS-1,0) {
        int poz=i*BASEDIGS+j;
        if(poz<n) d[i]=10*d[i]+s[n-1-poz]-'0';
      }
    }
    init(nd,d);
  }
  /* destruktor */
  ~Natural() { delete[] digs; }
  /* przypisanie */
  Natural &operator=(const Natural&a) {
    delete[] digs;
    init(a.ndigs,a.digs);
    return *this;
  }
  /* dodawanie */
  Natural operator+(const Natural&a) const {
    int n=max(ndigs,a.ndigs)+1;
    int d[n];
    REP(i,n) d[i]=0;
    REP(i,n) {
      if(i<ndigs) d[i]+=digs[i];
      if(i<a.ndigs) d[i]+=a.digs[i];
      if(d[i]>=BASE) { d[i]-=BASE; ++d[i+1]; }
    }
    return Natural(n,d);
  }
  Natural &operator+=(const Natural&a) {
    return *this = *this + a;
  }
  /* odejmowanie */
  Natural operator-(const Natural&a) const { // a <= *this
    int d[ndigs];
    REP(i,ndigs) d[i]=digs[i];
    REP(i,ndigs) {
      if (i < a.ndigs) d[i]-=a.digs[i];
      if (d[i] < 0) {
        d[i]+=BASE;
        --d[i+1];
      }
    }
    return Natural(ndigs,d);
  }
  Natural &operator-=(const Natural&a) {
    return *this = *this - a;
  }
  /* mno¿enie liczb */
  Natural operator*(const Natural&a) const {
    int n=ndigs+a.ndigs;
    int d[n];
    REP(i,n) d[i]=0;
    REP(i,ndigs) {
      int p=0;
      REP(j,a.ndigs) {
        long long v=(long long)(digs[i])*a.digs[j];
        int v1=v/BASE,v0=v%BASE;
        d[i+j]+=v0+p;
        p=v1+d[i+j]/BASE;
        d[i+j]%=BASE;
      }
      for(int j=i+a.ndigs;p>0;++j) {
        d[j]+=p;
        p=d[j]/BASE;
        d[j]%=BASE;
      }
    }
    return Natural(n,d);
  }
  Natural &operator*=(const Natural&a) {
    return *this = *this * a;
  }
  /* dzielenie liczb */
  Natural operator/(const Natural&a) const {
    int n=max(ndigs-a.ndigs+1,0);
    int d[n];
    Natural prod;
    FORD(i,n-1,0) {
      int l=0, r=BASE-1;
      while(l<r) {
        int m=(l+r+1)/2;
        if (*this<prod+(a*m<<i))
	  r=m-1;
	else
	  l=m;
      }
      prod+=a*l<<i;
      d[i]=l;
    }
    return Natural(n,d);
  }
  Natural &operator/=(const Natural&a) {
    return *this = *this / a;
  }
  /* modulo */
  Natural operator%(const Natural&a) const {
    return *this - *this/a*a;
  }
  Natural &operator%=(const Natural&a) {
    return *this = *this % a;
  }
  /* pierwiastek */
  Natural sqrt() const {
    int n=(ndigs+1)/2;
    int d[n];
    REP(i,n) d[i]=0;
    Natural sq;
    FORD(i,n-1,0) {
      Natural a(n,d);
      int l=0, r=BASE-1;
      while(l<r) {
        int m=(l+r+1)/2;
        if (*this<sq+(a*2*m<<i)+(Natural(m)*m<<2*i))
	  r=m-1;
	else
	  l=m;
      }
      sq+=(a*2*l<<i)+(Natural(l)*l<<2*i);
      d[i]=l;
    }
    return Natural(n,d);
  }
  /* mno¿enie przez inta */
  Natural operator*(int x) const { // !!! 0 <= x <= BASE
    int n=ndigs+1;
    int d[n];
    long long a=0;
    REP(i,ndigs) {
      a+=digs[i]*(long long)x;
      d[i]=a%BASE;
      a/=BASE;
    }
    d[ndigs]=a;
    return Natural(n,d);
  }
  Natural &operator*=(int x) {
    return *this = *this * x;
  }
  /* dzielenie przez inta */
  Natural operator/(int x) const { // !!! 0 < x
    int d[ndigs];
    long long a=0;
    FORD(i,ndigs-1,0) {
      a=BASE*a+digs[i];
      d[i]=a/x;
      a%=x;
    }
    return Natural(ndigs,d);
  }
  Natural &operator/=(int x) {
    return *this = *this / x;
  }
  /* modulo int */
  int operator%(int x) const { // !!! 0 < x
    long long a=0;
    FORD(i,ndigs-1,0) {
      a=BASE*a+digs[i];
      a%=x;
    }
    return a;
  }
  /* porównania (< potrzebne dla dzielenia i pierwiastka) */
  bool operator<(const Natural&a) const {
    if(ndigs<a.ndigs) return true;
    if(ndigs>a.ndigs) return false;
    FORD(i,ndigs-1,0) {
      if(digs[i]<a.digs[i]) return true;
      if(digs[i]>a.digs[i]) return false;
    }
    return false;
  }
  bool operator==(const Natural&a) const {
    if(ndigs!=a.ndigs) return false;
    REP(i,ndigs) {
      if(digs[i]!=a.digs[i]) return false;
    }
    return true;
  }
  bool operator>(const Natural&a) const { return a<*this; }
  bool operator<=(const Natural&a) const { return !(a<*this); }
  bool operator>=(const Natural&a) const { return !(*this<a); }
  bool operator!=(const Natural&a) const { return !(*this==a); }
  /* wypisywanie */
  void write() const {
    if(ndigs==0) printf("0");
    else {
      printf("%d",digs[ndigs-1]);
      FORD(i,ndigs-2,0) printf("%0*d",BASEDIGS,digs[i]);
    }
  }
  void write(char *buf) const {
    if(ndigs==0) sprintf(buf,"0");
    else {
      int pos=0;
      pos+=sprintf(buf,"%d",digs[ndigs-1]);
      FORD(i,ndigs-2,0) pos+=sprintf(buf+pos,"%0*d",BASEDIGS,digs[i]);
    }
  }
};



const int N = 550;
VI kalendarz[N];
int pos[N];
int dni, kalendarze;
Natural t[N];

Natural licz(){
	FOR(i,0,kalendarze) t[i] = Natural(0);
	t[0] = Natural(1);
	REP(i,kalendarze){
		FORD(j,i+1,0){
			t[j] *= (dni - pos[i]);
			if (j > 0) t[j] += t[j-1] * (pos[i]);
		}
	}
	Natural res(0);
	FOR(i,1,kalendarze) res += t[i] * (i*i);
	return res;
}

Natural nwd(Natural a, Natural b){
	if (b == Natural(0)) return a;
	return nwd(b, a%b);
}

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer_testu,testy){
    printf("Case #%d: ", numer_testu+1);
		scanf("%d %d", &dni, &kalendarze);
		REP(i,kalendarze) kalendarz[i].clear();
		REP(i, kalendarze){
			int k;
			scanf("%d",&k);
			kalendarz[i].PB(0);
			REP(foo,k-1){
				int x;
				scanf("%d",&x);
				kalendarz[i].PB(x-1);
			}
		}
		Natural res(0);
		Natural last(0);
		REP(i,kalendarze) pos[i] = 0;
		int koniec = 10100;
		int zmiany = 0;
		REP(dzien, min(dni, koniec)){
			int zmiana = 0;
			REP(i, kalendarze){
				if (pos[i] < SIZE(kalendarz[i]) && kalendarz[i][pos[i]] == dzien){
					pos[i]++;
					zmiana = 1;
				}
			}
			if (zmiana) {
				zmiany++;
				last = licz();
				res += last;
			} else res += last;
		}
		//printf("zmiany = %d\n", zmiany);
		if (dni > koniec){
			res += Natural(dni - koniec) * last;
		}
		Natural mianownik(1);
		REP(i,kalendarze) mianownik = mianownik * Natural(dni);
		/*
		res.write();
		printf(" ");
		mianownik.write();
		puts("");
		*/
		Natural calk = res / mianownik;
		res = res % mianownik;
		if (res == Natural(0)){
			mianownik = Natural(1);
		} else {
			Natural q = nwd(res, mianownik);
			res = res / q;
			mianownik = mianownik / q;
		}
		calk.write();
		printf("+");
		res.write();
		printf("/");
		mianownik.write();
		puts("");
		fflush(stdout);
  }
  return 0;
}
