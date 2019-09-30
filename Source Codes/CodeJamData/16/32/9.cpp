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


typedef long long ll;

int edge[55][55];
ll B,M,f[55];

int main() {
	IOS;

	f[0] = f[1] = 1;
	for (int i=2; i<55; i++)
		f[i] = f[i-1] * 2;
	int T;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		cin>>B>>M;
		cout<<"Case #"<<t<<": ";
		if (M > 1LL<<(B-2)) cout<<"IMPOSSIBLE"<<endl;
		else
		{
			cout<<"POSSIBLE"<<endl;
			for (int i=0; i<B; i++)
				for (int j=0; j<B; j++)
					edge[i][j] = 0;
			for (int i=0; i<B-1; i++)
				for (int j=i+1; j<B-1; j++)
					edge[i][j] = 1;
			for (int i=B-2; i>=0 && M; i--)
			{
				if (M >= f[i])
				{
					edge[i][B-1] = 1;
					M -= f[i];
				}
			}
			for (int i=0; i<B; i++)
			{
				for (int j=0; j<B; j++)
				{
					if (edge[i][j]) cout<<"1";
					else cout<<"0";
				}
				cout<<endl;
			}
		}
	}

	return 0;
}

