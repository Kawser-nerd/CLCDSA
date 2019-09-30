#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>
#define MAX(a,b) ((a)>(b))?((a):(b))
#define MIN(a,b) ((a)<(b))?((a):(b))
int cond = 1;
#define db(x) { if (cond) { cerr << __LINE__ << " " << #x << " " << x << endl; } }

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()


struct BigNum {
#define REDUCE() while(len>1 && cyf[len-1]==0) len--;
    static const int BASE=1000000000, BD=9;
    int len, al;
    LL* cyf;
    BigNum(int v=0, int l=2) {
        len=1; al=l;
        cyf = new LL[al];
        REP(x,al) cyf[x]=0;
        cyf[0]=v;
        if (v>=BASE) przen(1);
    }
    BigNum(const BigNum &a) {
        len=al=a.len;
        cyf = new LL[al];
        REP(x,al) cyf[x]=a.cyf[x];
    }
    ~BigNum(){delete cyf;}
    void Res(int l) {
        if (l>al) {
            l=max(l,2*al);
            LL* n = new LL[l];
            REP(x,l) n[x] = x>=al ? 0 : cyf[x];
            delete cyf;
            cyf = n;
            al = l;
        }
    }
    void przen(int p) {
        int x=0;
        for(;x<p || cyf[x]<0 || cyf[x]>=BASE;x++) {
            Res(x+2);
            if(cyf[x]<0){LL i=(-cyf[x]-1)/BASE+1; cyf[x]+=i*BASE; cyf[x+1]-=i;}else
                if(cyf[x]>=BASE){LL i=cyf[x]/BASE; cyf[x]-=i*BASE; cyf[x+1]+=i;}
        }
        len=max(len,x+1);
        REDUCE();
    }
    /* Operatory porownawcze */
#define OPER1(op) bool operator op (const BigNum &a) const
    OPER1(==) {
        if(a.len!=len) return 0;
        REP(x,len) if(cyf[x]!=a.cyf[x]) return 0;
        return 1;
    }
    OPER1(<) { 
        if(len!=a.len) return len<a.len;
        int x=len-1;
        while(x && a.cyf[x]==cyf[x]) x--;
        return cyf[x]<a.cyf[x];
    }
    OPER1(>) { return a<*this; } /* Wymaga < */
    OPER1(<=) { return !(a<*this); } /* Wymaga < */
    OPER1(>=) { return !(*this<a); } /* Wymaga < */
    OPER1(!=) { return !(*this==a); } /* Wymaga == */

    /* Operatory Bignum - Int */
    BigNum &operator=(int a) {
        REP(x,len) cyf[x]=0;
        len=1; cyf[0]=a; 
        if (a>=BASE) przen(1);
        return *this;
    }
    void operator+=(int a){cyf[0]+=a; przen(1);}
    void operator-=(int a){cyf[0]-=a; przen(1);}
    void operator*=(int a){REP(x,len) cyf[x]*=a; przen(len);}
    int operator/=(int a) { /* <b> Zwraca reszte z dzielenia </b> */
        LL w=0;
        FORD(p,len-1,0){w=w*BASE+cyf[p]; cyf[p]=w/a; w=w%a;}
        REDUCE();
        return w;
    }
    int operator%(int a) {
        LL w=0;
        FORD(p,len-1,0) w=(w*BASE+cyf[p])%a;
        return w;
    }
    /* Operatory Bignum - Bignum */
#define OPER2(op) BigNum& operator op (const BigNum &a)
    OPER2(+=) {
        Res(a.len);
        REP(x,a.len) cyf[x]+=a.cyf[x];
        przen(a.len);
        return *this;
    }
    OPER2(-=) {
        REP(x,a.len) cyf[x]-=a.cyf[x]; 
        przen(a.len);
        return *this;
    }
    OPER2(*=) {
        BigNum c(0,len+a.len);
        REP(x,a.len) {
            REP(y,len) c.cyf[y+x]+=cyf[y]*a.cyf[x];
            c.przen(len+x);
        }
        *this=c;
        return *this;
    }
    OPER2(/=) { /* Wymaga operatora <, += (BigNum) , *= (BigNum) , <<=, + (BigNum) , * (BigNum), << */
        int n=max(len-a.len+1,0);
        BigNum d(0,n), prod;
        FORD(i,n-1,0) {
            int l=0, r=BASE-1;
            while(l<r) {
                int m=(l+r+1)/2;
                if (*this < prod+(a*m<<i))
                    r=m-1;
                else
                    l=m;
            }
            prod+=a*l<<i;
            d.cyf[i]=l;
            if (l) d.len = max(d.len, i+1);
        }
        *this=d;
        return *this;
    }
    OPER2(%=) { /* Wymaga operatora <, += (BigNum) , -= (BigNum) *= (BigNum) , /= (BigNum) <<=, + (BigNum) , * (BigNum), << */
        BigNum v=*this;
        v/=a;
        v*=a;
        *this -= v;
        return *this;
    }
    OPER2(=) {
        Res(a.len);
        FORD(x, len-1, a.len) cyf[x]=0;
        REP(x,a.len) cyf[x]=a.cyf[x];
        len=a.len;
        return *this;
    }
    /* OPERATORY DO WCZYTYWANIA - WYPISYWANIA */
    void read(const vector<int> &v,int p) { /* Wymaga += (int), *= (int) */
        *this=0;
        FORD(x,v.size()-1,0) {
            *this *= p;
            *this += v[x];
        }
    }
    BigNum &operator=(string a) { /* Wymaga = (int) */
        int s=a.length();
        *this=0;
        Res(len=s/BD+1);
        REP(x,s) cyf[(s-x-1)/BD]=10*cyf[(s-x-1)/BD]+a[x]-'0';
        REDUCE();
        return *this;
    }
    void write() const {
        printf("%d", int(cyf[len-1]));
        FORD(x,len-2,0) printf("%0*d", BD, int(cyf[x]));
    }
    void write(char *buf) const {
        int p = sprintf(buf, "%d", int(cyf[len-1]));
        FORD(x,len-2,0) p += sprintf(buf+p, "%0*d", BD, int(cyf[x]));
    }
    vector<int> write(int pod) const { /* Wymaga /= (int), = (BigNum) */
        vector<int> w;
        BigNum v;
        v=*this;
        while(v.len>1 || v.cyf[0]) w.PB(v/=pod);
        return w;
    }
    /* Inne operatory */ 
    BigNum &operator<<=(int ile) {
        if(cyf[0]==0 && len==1) return *this;
        Res(len+ile);
        FORD(x,len-1,0) cyf[x+ile]=cyf[x];
        REP(x,ile) cyf[x]=0;
        len+=ile;
        return *this;
    }
    BigNum &operator>>=(int ile) {
        if(ile>=len) ile=len;
        REP(x,len-ile) cyf[x]=cyf[x+ile];
        FOR(x,len-ile,ile) cyf[x]=0;
        len-=ile;
        if(len==0) len=1;
        return *this;
    }
    BigNum sqrt() { /* Wymaga <, += (BigNum), *= (BigNum), <<= (int), + (BigNum), * (BigNum), << (int) */
        int n=(len+1)/2;
        BigNum a(0,n), sq;
        FORD(i,n-1,0) {
            int l=0, r=BASE-1;
            while(l<r) {
                int m=(l+r+1)/2; 
                if (*this < sq+(a*2*m<<i)+(BigNum(m)*m<<2*i))
                    r=m-1;
                else
                    l=m;
            }
            sq+=(a*2*l<<i)+(BigNum(l)*l<<2*i);
            a.cyf[i]=l; a.len=n;
        }
        return a;
    }
#define OPER3(op) BigNum operator op(const BigNum &a) const {BigNum w=*this;  w op ## = a;  return w; }
#define OPER4(op) BigNum operator op(int a) {BigNum w = *this; w op ## = a; return w; }
    OPER3(+); /* Wymaga += (BigNum) */
    OPER3(-); /* Wymaga -= (BigNum) */
    OPER3(*); /* Wymaga *= (BigNum) */
    OPER3(/); /* Wymaga operatora <, += (BigNum) , *= (BigNum) , /= (BigNum) <<=, + (BigNum) , * (BigNum), << */
    OPER3(%); /* Wymaga operatora <, += (BigNum) , -= (BigNum), *= (BigNum) , /= (BigNum), %= (BigNum), <<=, + (BigNum) , * (BigNum), << */
    OPER4(<<); /* Wymaga <<= (int) */
    OPER4(>>); /* Wymaga >>= (int) */
};


BigNum nwd(BigNum a, BigNum b) {
    if (a == 0) return b;
    return nwd(b % a, a);
}

//Begin of the code
void solve() {
    int k;
    scanf("%d", &k);
    BigNum a[10000];

    rep (i, k) {
        char buf[100] = {};
        scanf("%s", buf);

        vector<int> q;
        for (int j = strlen(buf) - 1; j >= 0; j--) q.push_back(buf[j] - '0');
        a[i].read(q, 10);
    }
    bool init = 0;
    BigNum nw = 1;
    rep (i, k) rep (j, k) {
        if (a[i] > a[j]) {
            if (init == 0) {
                init = 1;
                nw = a[i] - a[j];
            }
            else
                nw = nwd(nw, a[i] - a[j]);
        }
    }
    if (init == 0) {
        printf(" 0");
        return;
    }
    BigNum minval = a[0];
    rep (i, k) if (a[i] < minval) minval = a[i];
    BigNum ret = minval / nw * nw;
    while (ret < minval) ret += nw;

    BigNum wynik = ret - minval;

    printf(" ");
    wynik.write();
}

int main(int argc, char ** argv) {
    int t;
    scanf("%d", &t);
    rep (i, t) {
        printf("Case #%d:", i+1);
        solve();
        printf("\n");
    }
    return 0;
}



