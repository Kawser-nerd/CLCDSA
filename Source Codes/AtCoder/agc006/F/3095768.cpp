#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*
cout<<setprecision(20);
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}

int main(void){
	int n,m,i;cin>>n>>m;
	llint ans=0;
	vector<vector<int>>go(n);
	vector<vector<int>>ro(n);
	for(i=0;i<m;i++){
		int a,b;cin>>a>>b;a--;b--;
		go[a].pub(b);
		ro[b].pub(a);
	}
	vector<int>col(n,-1);
	vector<int>sla(n,-1);
	queue<int>que;
	for(i=0;i<n;i++){
		if(col[i]!=-1){continue;}
		//???????????????????
		llint kaz[3]={0};
		bool bra=0;
		que.push(i);
		col[i]=0;sla[i]=0;
		int su=0,st=0;
		llint cou=0;
		while(que.size()){
			int ter=que.front();
			que.pop();
			int c=col[ter];
			int s=sla[ter];
			maxeq(su,s);
			mineq(st,s);
			kaz[c]++;
			for(auto it:go[ter]){
				cou++;
				if(col[it]==-1){sla[it]=s+1;col[it]=(c+1)%3;que.push(it);}
				else if(col[it]!=(c+1)%3){bra=1;}
			}
			for(auto it:ro[ter]){
				if(col[it]==-1){sla[it]=s-1;col[it]=(c+2)%3;que.push(it);}
				else if(col[it]!=(c+2)%3){bra=1;}
			}
		}
		if(bra){ans+=(kaz[0]+kaz[1]+kaz[2])*(kaz[0]+kaz[1]+kaz[2]);}
		else if(su-st<2){ans+=cou;}
		else{ans+=kaz[0]*kaz[1]+kaz[1]*kaz[2]+kaz[2]*kaz[0];}
	}
	cout<<ans<<endl;
	return 0;
}