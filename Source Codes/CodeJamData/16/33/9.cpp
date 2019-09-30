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


int A,B,C,K;
int app[3][10][10];

int main() {
	IOS;

	int T;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		cin>>A>>B>>C>>K;
		int cnt = A*B*min(C,K);
		cout<<"Case #"<<t<<": "<<cnt<<endl;
		int tot = 0;
		FZ(app);
		for(int i=0; i<A; i++)
			for(int j=0; j<B; j++)
				for(int k=0; k<C; k++)
					if ((i+j+k)%C < K)
					{
						cout << i+1 << " " << j+1 << " " << k+1 << endl;
						app[0][i][j]++;
						app[1][i][k]++;
						app[2][j][k]++;
						tot++;
					}
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<10; j++)
			{
				for(int k=0; k<10; k++)
				{
					assert(app[i][j][k] <= K);
				}
			}
		}

		assert(tot == cnt);
	}

	return 0;
}

