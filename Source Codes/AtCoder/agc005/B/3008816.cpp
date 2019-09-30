#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n,a[201001]={};
	cin>>n;
	priority_queue<pair<int,int>> pq;
	map<int,int> mp;
	LL ans=0LL;
	FOR(i,0,n){
		cin>>a[i];
		pq.push(MP(-a[i],i+1));
	}
	mp[0]=1;mp[n+1]=1;
	while(pq.size()){
		pair<int,int> pr=pq.top();
		pq.pop();
		pr.ST=-pr.ST;
		mp[pr.ND]=1;
		auto it=mp.find(pr.ND);
		auto itl=--it;
		it++;
		auto itr=++it;
		it--;
		ans+=1LL*pr.ST*(it->ST-itl->ST)*(itr->ST-it->ST);
		//cerr<<pr.ST<<" "<<ans<<endl;
	}

	cout<<ans;
    return 0;
}