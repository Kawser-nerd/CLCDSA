#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

// BUG FOR LARGE, NEED LONG LONG
// BUG FOR LARGE, TL

ll stupid(int k,ll c){
	ll sum = 0;
	ll num = 0;
	for(ll i=1;i<=c;i++){
		ll n = k - sum/i;
		sum += n*i;
		num += n;
	}
	return num;
}

ll clever(int k,ll c){
	ll res = 0;
	ll sum = 0;
	for(ll i=1;i<=c;){
		ll xx = k - sum/i;
		if(xx==0) {
			if( i == sum/k) i++;
			else i = max(i,sum/k);
			continue;
		}
		ll num = 0;

		ll a = 0, b = max(0ll,min(c-i+1,c*k/xx/i)-1);
		while(a<=b){
			ll s = (a+b)/2;

			bool good = false;

			ll add = xx * (i+i+s-1)*s/2;
			if(k - sum - add / (i+s) == xx) good=true;


			if(good) a = s+1,num=s;
			else b = s-1;
		}

		num++;

		sum += xx * (i+i+num-1)*num/2;
		res += xx * num;
		i += num;
	}	
	return res;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	//cout<<clever(1,1000000000000)<<endl;
	//return 0;
	int  TC;
	cin>>TC;
	REP(tc,TC){
		int k;
		ll c;
		cin>>k>>c;		
		//k = rand()%1000+1;
		//c = ll(rand())+1;
		printf("Case #%d: ",tc+1);
		//cout<<stupid(k,c)<<' '<<clever(k,c)<<endl;
		//if(stupid(k,c)!=clever(k,c))
//while(1)			puts("FUCK");
	//	else
		//cout<<c<<endl;
		cout<<clever(k,c)<<endl;
		//tc--;
		
	}

	return 0;
}