#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int inf = (int)1E+9;

typedef long long int64;
typedef pair<int,int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define last(a) (int)a.size() - 1
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())

const int nmax = 25;
const int smax = 750*2;
const int nol = smax / 2;

const int px[4] = {1,-1,0,0};
const int py[4] = {0,0,1,-1};

char a[nmax][nmax];
string t[nmax][nmax][smax];
int used[nmax][nmax][smax];
int n,m;


bool ls(string s1, string s2){
	if (s1.length() != s2.length())
		return s1.length() > s2.length();
	return s1 > s2;
}

void solve(){
	cin >> n >> m;
	forn(i,n)
		forn(j,n)
			cin >> a[i][j];
//	forn(i,n){
//		forn(j,n)
//			cerr << a[i][j];
//		cerr << endl;
//	}
	queue<pair<pii,int> >q;

	forn(i,n)
		forn(j,n)
			forn(k,smax)
				t[i][j][k] = "";
	forn(i,n)
		forn(j,n)
			if (isdigit(a[i][j])){
				q.push(mp(mp(i,j), a[i][j] -'0' + nol));
				t[i][j][a[i][j]-'0' + nol] = a[i][j];
				used[i][j][a[i][j]-'0'+nol] ++;
			}
	
	//forn(qwe,50){
	while(!q.empty()){
		pair<pii, int> now = q.front();
		q.pop();
		int i = now.fs.fs;
		int j = now.fs.sc;
		int k = now.sc;
		used[i][j][k] --;
		forn(l,4){
			int nx = i + px[l];
			int ny = j + py[l];
			if (nx < 0 || ny < 0) continue;
			if (nx >= n || ny >= n) continue;
			int now = k - nol;
			if (isdigit(a[nx][ny])){
				if (a[i][j] == '+')
					now += a[nx][ny] - '0';
				else
					now -= a[nx][ny] - '0';
			}
			if (now >= nol)continue;
			if (now <= -nol)continue;
			if (t[nx][ny][nol + now] == "" || ls(t[nx][ny][nol + now], t[i][j][k] + a[nx][ny])){
				t[nx][ny][nol + now] = t[i][j][k] + a[nx][ny];
				if (used[nx][ny][now+nol] == 0){
					q.push(mp(mp(nx,ny),now+nol));
					used[nx][ny][now+nol]++;
				}
			}
		}
	}
	forn(i,m){
		int e;
		cin >> e;
		string res = "";
		forn(i,n)
			forn(j,n)
				if (t[i][j][nol+e] != "" && (res == "" || ls(res, t[i][j][nol + e]))){
					res = t[i][j][nol + e];
				}
		assert(res != "");
		cout << res << endl;
	}

							       
							
									              
}

int main(){
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int tst;

	cin >> tst;
	forn(i,tst){
		printf("Case #%d:\n",i+1);
		solve();
	}	

}
