#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <fstream>
#include <set>
#include <map>

#define FOR(i,a,b)  for(__typeof(b) i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define FOREACH(x,c)   for(__typeof(c.begin()) x=c.begin();x != c.end(); x++)
#define ALL(c)      c.begin(),c.end()
#define CLEAR(c)    memset(c,0,sizeof(c))
#define SIZE(c) (int) ((c).size())

#define PB          push_back
#define MP          make_pair
#define X           first
#define Y           second

#define ULL         unsigned long long
#define LL          long long
#define LD          long double
#define II         pair<int, int>
#define DD         pair<double, double>

#define VC	    vector
#define VI          VC<int>
#define VVI         VC<VI>
#define VD          VC<double>
#define VS          VC<string>
#define VII         VC<II>
#define VDD         VC<DD>

#define DB(a)       cerr << #a << ": " << a << endl;

using namespace std;

template<class T> void print(VC < T > v) {cerr << "[";if (SIZE(v) != 0) cerr << v[0]; FOR(i, 1, SIZE(v)) cerr << "," << v[i]; cerr << "]\n";}
template<class T> string i2s(T &x) { ostringstream o; o << x; return o.str(); }
VS split(string &s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < SIZE(s)) all.PB(s.substr(p)); return all;}

int n;
VS cars;

void readTest(){
    scanf("%d",&n);
    char buf[200];
    cars.clear();
    REP(i,n){
        scanf("%s",buf);
        cars.PB(string(buf));
    }
}

#define MOD 1000000007ULL

map<char,int> sng;
VS ncars;

int isConst(string s){
    for(auto c : s) if (c != s[0]) return 0;
    return 1;
}

void split(){
    sng.clear();
    ncars.clear();
    for(auto c : cars)
        if (!isConst(c))
            ncars.PB(c);
        else
            sng[c[0]]++;
}

void join(){
    int m = SIZE(ncars);
    int ok;
    do{
        ok = 1;
        REP(i,m){ 
            REP(j,m) if (i != j && ncars[i].back() == ncars[j][0]){
                ok = 0;
                string s = ncars[i]+ncars[j];
                int i1 = min(i,j);
                int i2 = max(i,j);
                ncars[i1] = s;
                ncars[i2] = ncars.back();
                ncars.pop_back();
                m--;
                break;
            }
            if (!ok)
                break;
        }
    } while (!ok);
}

int check(string s){
    set<char> used;
    char prev = ' ';
    REP(i,SIZE(s))
        if (s[i] != prev){
            if (used.find(s[i]) != used.end())
                return 0;
            else
                used.insert(s[i]);
            prev = s[i];
        }
    return 1;
}

ULL fact(int n){
    ULL res = 1;
    FOR(i,1,n+1){
        res = (res*i) % MOD;
    }
    return res;
}
int check(ULL &res){
    for(auto p : sng){
        ncars.PB(string(1,p.X));
        //res = (res*fact(p.Y)) % MOD;
    }
    string ss("");
    for(auto s : ncars) ss = ss + s;
    //DB(ss);
    return check(ss);
}


ULL joinSingles(){
    ULL res = 1;
    vector<char> toRemove;
    for(auto s : sng){
        res = (res * fact(s.Y)) % MOD;
        for(auto car : ncars)
            if (car[0] == s.X || car.back() == s.X)
                toRemove.PB(s.X);
    }
    for(auto c : toRemove)
        sng.erase(c);
    return res;
}

void solveTest(int t){
    split();
    //DB(SIZE(sng)); DB(SIZE(ncars));
    ULL res = joinSingles();
    //DB(res);
    //DB(SIZE(sng)); DB(SIZE(ncars));
    join();
    //DB(SIZE(ncars));
    printf("Case #%d:",t);
    if (!check(res)){
        printf(" 0\n");
        return;
    }
    //DB(res);
    res = (res * fact(SIZE(ncars))) % MOD;
    //DB(res);
    printf(" %llu\n",res);
}

int main(int argc, char *argv[]){
    int T;
    scanf("%d",&T);
    REP(t,T){
        readTest();
        solveTest(t+1);
    }
    return 0;
}
