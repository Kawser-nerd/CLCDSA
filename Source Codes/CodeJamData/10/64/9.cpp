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

int n;
ll x[22];
ll f;
ll res =-1;

ll A(ll v){return v<0?-v:v;}
void go(int pos,int mask,ll sum=0){
	if(pos==0 && mask==(1<<n)-1 && sum<=f) res=max(res,sum);
	if(sum>f) return;
	if(pos==0 && mask) return;
	REP(i,n) if(i!=pos) if(!(mask&(1<<i)))
		go(i,mask|(1<<i),sum+A(x[i]-x[pos]));

}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int TC;
	cin>>TC;
	REP(tc,TC){
		cin>>n;
		REP(i,n) cin>>x[i];
		cin>>f;
		res = -1;
		go(0,0);
		if(res == -1) printf("Case #%d: NO SOLUTION\n",tc+1);
		else printf("Case #%d: %lld\n",tc+1,res);
	}
	

	return 0;
}