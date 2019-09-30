#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+10;
LL ds[L];

void mul(vector<int>& a,vector<int>& b,vector<int>& c)
{
	assert(a.size()==b.size()&&a.size()==c.size());
	for(int i=0;i<c.size();i++){
		assert(0<=a[i]&&a[i]<a.size());
		c[i]=b[a[i]];
	}
}
vector<int> pw(vector<int> a,LL n)
{
	vector<int> p(a.size());
	vector<int> buf(a.size());
	for(int i=0;i<p.size();i++){
		p[i]=i;
	}

	while(n){
		if(n&1){
			mul(a,p,buf);
			buf.swap(p);
		}
		mul(a,a,buf);
		buf.swap(a);
		n/=2;
	}
	return p;
}

int main() {
	int N;
	cin >> N;
	LL p0;
	cin >> p0; 
	LL pre=p0;
	for(int i=0;i<N-1;i++){
		LL v;
		cin >> v;
		ds[i]=v-pre;
		pre=v;
	}
	vector<int> p(N-1);
	for(int i=0;i<N-1;i++){
		p[i]=i;
	}
	LL M,K;
	cin >> M >> K;
	for(int i=0;i<M;i++){
		int a;
		cin >> a;
		a--;
		swap(p[a-1],p[a]);
	}
	p=pw(p,K);
	assert(p.size()==N-1);
	cout << p0 << endl;
	pre=p0;
	for(int i=0;i<N-1;i++){
		pre+=ds[p[i]];
		cout << pre << endl;
	}

	return 0;
}