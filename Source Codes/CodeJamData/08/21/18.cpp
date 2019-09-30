#define _CRT_SECURE_NO_DEPRECATE
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<numeric>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(I,S,N) for(int I=(S);I<(N);++I)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";int __prv;REP(__prv,sz(X)-1) cout<<(X)[__prv]<<",";cout<<(X).back()<<"}"<<endl;}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define SS stringstream
template<typename T> string tos(T q,int w=0){SS A;A.flags(ios::fixed);A.precision(w);A<<q;string s;A>>s;return s;}
template<typename T> T sto(string s){SS A(s);T t;A>>t;return t;}
template<typename T> vector<T > s2v(string s){SS A(s);vector<T > ans;while(A&&!A.eof()){T t;A>>t;ans.pb(t);}return ans;}
	
// end of pre-inserted code

#define DIM 110000
lint x[DIM],y[DIM];

lint r[3][3];

int main() {
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d ",&tc);
	FOR(tn,1,tc+1) {
		int n,a,b,c,d,x0,y0,m;
		scanf("%d %d %d %d %d %d %d %d ",&n,&a,&b,&c,&d,&x0,&y0,&m);
		lint xx = x0, yy = y0;
		x[0] = xx;
		y[0] = yy;
		FOR(i,1,n) {
			xx = (a * xx + b) % m;
			yy = (c * yy + d) % m;
			x[i] = xx;
			y[i] = yy;
		}

		memset(r,0,sizeof(r));
		
		REP(i,n) ++r[x[i]%3][y[i]%3];

		lint ans = 0;
		REP(i, 9) {
			REP(j, 9) {
				int xr1 = i/3, xr2 = j/3, xr3;
				int yr1 = i % 3, yr2 = j % 3, yr3;
				xr3 = (9 - xr1 - xr2) % 3;
				yr3 = (9 - yr1 - yr2) % 3;
				int k = xr3*3 + yr3;				
				if(i != j && i != k && k != j) {
					ans += r[xr1][yr1]*r[xr2][yr2]*r[xr3][yr3];
				}
				else if (i == j && i == k && j == k) {
					if(r[xr1][yr1] >= 3) {
						ans += r[xr1][yr1]*(r[xr1][yr1]-1)*(r[xr1][yr1]-2);
					}
				}
				else if(i == j) {
					if(r[xr1][yr1] >= 2) {
						ans += r[xr1][yr1]*(r[xr1][yr1]-1)*r[xr3][yr3];
					}
				}
				else if(i == k) {
					if(r[xr1][yr1] >= 2) {
						ans += r[xr1][yr1]*(r[xr1][yr1]-1)*r[xr2][yr2];
					}
				}
				else if(j == k) {
					if(r[xr2][yr2] >= 2) {
						ans += r[xr2][yr2]*(r[xr2][yr2]-1)*r[xr1][yr1];
					}
				}

			}
		}
		ans /= 6;
		printf("Case #%d: %lld\n",tn,ans);
	}
	fclose(stdout);
	return 0;
}