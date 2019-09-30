#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
long long int MOD = 1000000007;
vector<int> temp[500005];
int powmod(int x, int y, int z){//x*y^z
	long long int ori,mul,num;
	ori=(ll)x;
	mul=(ll)y;
	num=(ll)z;
	while(num > 0){
		if(num &1){
			ori *= mul;
			ori %= MOD;
		}
		mul*=mul;
		mul %= MOD;
		num = num>>1;
	}
	return ori;
}


int main(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<int>nums;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		nums.pb(x);
	}	
	sort(nums.begin(),nums.end());
	if(a==1){
		for(int i=0;i<n;i++){
			cout<<nums[i]<<endl;
		}
	}else{
		vector<pair<double,pii> >hoge;
		for(int i=0;i<n;i++){
			double y;
			y=log( (double)nums[i] )/log( (double)a );
			hoge.pb(mp(y,mp(0,nums[i]) ));
		}
		
		//rep(i,n)cout<<hoge[i].first<<endl;
		while(1){
			int k=n-1;
			double mi=hoge[n-1].first;
			for(int i=n-1;i>=0;i--){
				if(hoge[i].first<=mi){
					mi=hoge[i].first;
					k=i;
					//cout<<k;
				}
			}
			b--;
			if(k==n-1){
				hoge[k].second.first++;
				hoge[k].first++;

				break;
				
			}else{
				hoge[k].second.first++;
				hoge[k].first++;
				
			}
			if(b==0)break;
			/*rep(i,n)cout<<hoge[i].first<<" ";
			cout<<endl;*/
		}
		rep(i,n){
			hoge[i].second.first+=b/n;
			hoge[i].first+=b/n;
		}
		sort(hoge.begin(),hoge.end());
		b=b%n;
		rep(i,b)hoge[i].second.first++,hoge[i].first++;
		sort(hoge.begin(),hoge.end());
		//reverse(hoge.begin(),hoge.end());
		rep(i,n){
					cout<<powmod(hoge[i].second.second,a,hoge[i].second.first)<<endl;
		}
	}
	
	
	
}