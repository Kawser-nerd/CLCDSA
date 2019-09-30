#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef unsigned long long ull;
const int med=250000;
ull powmod(ull a, ll k){
    if(a==0) return 0;
    ull ap=a, ans=1;
    while(k>0){
        if(k%2==1){
            ans*=ap;
        }
        ap=ap*ap;
        k/=2;
    }
    return ans;
}
ull inv(ull a){
	return powmod(a, (1ll<<63)-1);
}

int main()
{
	int n;
	cin>>n;
	//char s[250000];
  //for(int i=0; i<n; i++){
    //if(i%4==0) s[i]='+';
    //else if(i%4==1) s[i]='<';
    //else if(i%4==2) s[i]='>';
    //else s[i]='-';
  //}
  string s; cin>>s;
    //random_device rnd;
	//mt19937_64 mt(rnd());
	//uniform_int_distribution<ll> rndn(2, MOD-2);
	//ll b=rndn(mt);
  ull b=67;
	ull binv=inv(b);
	ull bp[500001];
	bp[med]=1;
	for(int i=med+1; i<=med+n; i++) bp[i]=bp[i-1]*b;
	for(int i=med-1; i>=med-n; i--) bp[i]=bp[i+1]*binv;
	ull b0=0; int p=med;
	for(int i=0; i<n; i++){
		if(s[i]=='+'){
			b0=b0+bp[p];
		}else if(s[i]=='-'){
			b0=b0-bp[p];
		}else if(s[i]=='>'){
			p++;
		}else{
			p--;
		}
	}
	ll ans=0;
	ull x[250000]={};
	unordered_map<ull, int> mp[500];
	int c1[500]={};
	ull c0[500]={};
	int sq=2000;
	for(int i=0; i<n; i++){
		if(s[n-1-i]=='+'){
			for(int j=i/sq*sq; j<=i; j++){
				x[j]++;
			}
			for(int j=0; j<i/sq; j++){
				c0[j]++;
			}
		}else if(s[n-1-i]=='-'){
			for(int j=i/sq*sq; j<=i; j++){
				x[j]--;
			}
			for(int j=0; j<i/sq; j++){
				c0[j]--;
			}
		}else if(s[n-1-i]=='>'){
			for(int j=i/sq*sq; j<=i; j++){
				x[j]*=b;
			}
			for(int j=0; j<i/sq; j++){
				c1[j]++;
				c0[j]*=b;
			}
		}else{
			for(int j=i/sq*sq; j<=i; j++){
				x[j]*=binv;
			}
			for(int j=0; j<i/sq; j++){
				c1[j]--;
				c0[j]*=binv;
			}
		}
		for(int j=0; j<i/sq; j++){
			ull x0=(b0-c0[j])*bp[med-c1[j]];
			auto itr=mp[j].find(x0);
          if(itr!=mp[j].end()) ans+=((ll)(itr->second));
		}
		for(int j=i/sq*sq; j<=i; j++){
			if(b0==x[j]) ans++;
		}
		if((i+1)%sq==0){
			for(int j=i/sq*sq; j<=i; j++){
				mp[i/sq][x[j]]++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}