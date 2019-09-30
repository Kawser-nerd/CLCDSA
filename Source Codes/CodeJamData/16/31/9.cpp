#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define REP(i,x) for (int i=0; i<(x); i++)
#define REP1(i,a,b) for (int i=(a); i<=(b); i++)
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#else
#define FILEIO(name)
#endif
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
    return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s<<"[ ";
    for (auto it : c) s << it << " ";
    s<<"]";
    return s;
}
// Let's Fight!


const int MAXN = 30;

int N;
int p[MAXN];

char take()
{
	int mx = 0;
	for(int i=0; i<N; i++)
		if(p[i] > p[mx])
			mx = i;
	p[mx]--;
	return 'A' + mx;
}

string calc()
{
	string ret = "";

	int tot = 0;
	for(int i=0; i<N; i++)
		tot += p[i];
	
	while(tot > 0)
	{
		ret += " ";
		ret += take();
		tot--;
		if(tot != 2)
		{
			ret += take();
			tot--;
		}
	}

	return ret;
}

int main() {
	IOS;

	int T;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>p[i];

		string res = calc();
		cout<<"Case #"<<t<<":"<<res<<endl;
	}

	return 0;
}

