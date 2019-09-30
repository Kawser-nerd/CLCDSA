#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<m;i++)
#define rep2(i,x,m) for(int i=x;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
int oo = (int) 1e9;
int n,w,q;
string s[5000];
string str;
vector<string> p;
int main() {
//#define SAMPLE
#ifndef SAMPLE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif
#ifdef SAMPLE
	freopen("a.txt", "rt", stdin);
#endif
	cin>>n>>w>>q;
	rep(i,w)
		cin>>s[i];
	rep(i,q){
		cin>>str;
		int ret=0;
		p.clear();
		rep(j,str.sz)
			if(str[j]=='('){
				int k=j;
				for(;;k++)
					if(str[k]==')')
						break;
				p.pb(str.substr(j+1,k-j-1));
				j=k;
			}else
				p.pb(str.substr(j,1));
		rep(j,w){
			rep(k,n){
				rep(z,p[k].sz)
					if(p[k][z]==s[j][k])
						goto EE;
				goto END;
				EE:;
			}
			ret++;
			END:;
		}
		printf("Case #%d: %d\n",i+1,ret);
	}
	return 0;
}
