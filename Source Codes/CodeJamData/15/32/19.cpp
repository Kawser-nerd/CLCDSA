#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int check(string s)
{
	int n = s.length();
	for(int i=1; i<n; i++)
	{
		int bad = 0;
		for(int j=0 ; j<n; j++)
		{
			if(i+j >= n)break;
			if(s[j] != s[i+j])bad = 1;
		}
		if(bad == 0)return i;
	}
	return n;
}

void solve()
{
	int k,l,s;
	int cnt[100];
	for(int i=0; i<100; i++)cnt[i]=0;
	cin>>k>>l>>s;
	string keys;
	cin>>keys;
	for(int i=0; i<k; i++)
		cnt[keys[i] - 'A']++;
	string target;
	cin>>target;
	int nakladka = check(target);
	//cout<<"nakladka = "<<nakladka<<endl;
	
	int zmieszcze = (s-target.size())/nakladka + 1;
	for(int i=0; i<l; i++)if(cnt[target[i] - 'A'] == 0)zmieszcze = 0;

	double exi = 1.0;
	for(int i=0; i<l; i++)
	{
		exi *= ((double) cnt[target[i] - 'A']) / ((double) k);
	}
	cout<<setprecision(9);
	//cout<<"zmieszcze = "<<zmieszcze<<endl;
	cout<<zmieszcze - exi * (s-l+1)<<"\n";
}

int main()
{
    IOS
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
