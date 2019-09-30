#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int MAXN = 1000;
const double p = 1. / MAXN, q = 1-p;

double prob[2][MAXN][MAXN];

int main() {
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        
        int act = 0, next = 1;
        forn(i,MAXN) prob[act][i][i] = 1.0;
        forn(i,MAXN) {
        	fill(prob[next][0], prob[next][MAXN], 0.0);
        	forn(j,MAXN) {
        		if (i != j) {
        			forn(k,MAXN) {
        				prob[next][j][k] += q * prob[act][j][k];
        				prob[next][i][k] += p * prob[act][j][k];
        			}
        		}        		
        	}
        	forn(j,MAXN) forn(k,MAXN) {
        		prob[next][j][k] += p * prob[act][i][k];
        	}

        	swap(act, next);
        }


        int ncas; cin >> ncas;
        forn(cas, ncas) {
        	cout << "Case #" << cas+1 << ": ";
        	int n; cin >> n;

        	double res = 1;
        	forn(i,n) {
        		int xi; cin >> xi;
        		res *= prob[act][i][xi] * n;
        	}
        	if (res > 1) cout << "BAD" << endl;
        	else cout << "GOOD" << endl;
        }

        return 0;
}
