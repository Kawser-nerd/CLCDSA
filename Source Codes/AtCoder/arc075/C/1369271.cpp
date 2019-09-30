/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
typedef pair<ii,ii> iiii;
long long mod = 1000000007LL;
long long base = 37;
long long large = 1000000000000000000LL;


int up;
long long uv;
vector<long long> sum;
int sz;

void update(int o,int l,int r){
	if(l==r){
		sum[o]+=uv;
	}else{
		int m = (l+r)/2;
		if(up<=m) update(o*2,l,m);
		if(up>m) update(o*2+1,m+1,r);
		sum[o]=sum[o*2]+sum[o*2+1];
	}
}

int ql,qr;
long long re;
void query(int o,int l,int r){
	if(ql<=l&&qr>=r){
		re+=sum[o];
	}else{
		int m = (l+r)/2;
		if(ql<=m) query(o*2,l,m);
		if(qr>m) query(o*2+1,m+1,r);
	}
}
int main(){

	int n;
	cin>>n;
	vector<long long> s(n,0);
	long long k;
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(i) s[i]+=s[i-1];
	}
	vector<long long> p(n,0);
	for(int i=0;i<n;i++){
		p[i]=1LL*(i+1)*k-s[i];
	}
	map<long long,int> comp;

	vector<long long> a=p;
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	for(int i=0;i<(int)a.size();i++) comp[a[i]]=i;
	sz = (int)a.size();
	sum.assign(4*sz+10,0LL);
	long long ans = 0LL;
	for(int i=0;i<n;i++){
		qr=sz-1;
		ql=comp[p[i]];
		re=0LL;
		query(1,0,sz-1);
		ans+=re;
		uv=1LL;
		up=comp[p[i]];
		update(1,0,sz-1);
	}
	for(int i=0;i<n;i++) if(s[i]>=1LL*(i+1)*k) ans++;


	cout<<ans<<endl;



	/*int totalcase;
	int testcase=0;
	cin>>totalcase;
	ofstream out;
	out.open("result.txt");

	while(totalcase--){
		testcase++;
		out<<"Case #"<<testcase<<": ";
		cout<<testcase<<": "<<endl;

		//GOGOGO


		//END
	}
	out.close();*/

	return 0;
}