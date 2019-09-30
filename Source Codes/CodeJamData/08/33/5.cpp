#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAXZ = 500100;

int T;
ll A[MAXZ];
ll B[MAXZ];
ll F[MAXZ];
ll G[MAXZ];
map<ll, ll> table;
ll n, m, X, Y, Z;
const ll S = 1000000007;

ll _find(int l, int r, int i){
	int mid = (l+r)/2;
	
	ll ret = 0;
	if (mid <= i)
		ret += G[mid];
		
	if (mid == i) return (ret%S);
	
	if (i <= mid)
		ret += _find(l, mid-1, i);
	else
		ret += _find(mid+1, r, i);
		
	return (ret%S);
}

void _updata(int l, int r, int i, ll w){
	int mid = (l+r)/2;
	
	if (i <= mid)
		G[mid] = (G[mid] + w) % S;
		
	if (i == mid) return;
	
	if (i < mid)
		_updata(l, mid-1, i, w);
	else
		_updata(mid+1, r, i, w);
}

int main(){
	ifstream cin("c2.in");
	ofstream cout("c2.out");
	
	cin>>T;
	for (int Case=1; Case<=T; ++Case){
		cin>>n>>m>>X>>Y>>Z;
		for (int i=0;i<m;++i){
			int k;
			cin>>k;
			A[i] = k;
		}
		
		int cnt=0;
		for (int i=0; i<n; ++i){
			B[cnt++] = A[i%m];
			A[i%m] = (X*A[i%m] + Y*(i+1)) % Z;
		}
		
		for (int i=0; i<n; ++i) A[i] = B[i];
		sort(A, A+n);
		
		int tot = 0;
		table.clear();
		for (int i=0;i<n;){
			table[A[i]] = tot++;
			int j = i;
			while ((j<n)&&(A[i]==A[j]))j++;
			i = j;
		}
		
		ll ret=0;		
		memset(G, 0, sizeof(G));
		for (int i=0;i<n;++i){
			F[i] = 1;
			
			int k = table[B[i]];
			if (k > 0) 
				F[i] = (F[i]+ _find(0, tot, k-1))% S;
				
			_updata(0, tot, k, F[i]);
			
			ret = (ret + F[i]) % S;
		}
		
		cout<<"Case #"<<Case<<": "<<ret<<endl;
	}	
	
	return 0;
}
