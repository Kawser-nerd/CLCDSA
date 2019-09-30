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
const llint mod=924844033;
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
	cout<<setprecision(20);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m,i;cin>>n>>m;
	string str;cin>>str;
	vector<bool>ok(n,true);
	vector<vector<int>>go(n);
	vector<int>A(n);
	vector<int>B(n);
	for(i=0;i<m;i++){
		int u,v;cin>>u>>v;u--;v--;
		go[u].pub(v);
		go[v].pub(u);
		if(str[u]=='A'){A[v]++;}else{B[v]++;}
		if(str[v]=='A'){A[u]++;}else{B[u]++;}
	}
	queue<int>que;
	for(i=0;i<n;i++){
		if(A[i]==0||B[i]==0){que.push(i);ok[i]=0;}
	}
	while(que.size()>0){
		int t=que.front();que.pop();
		for(auto it:go[t]){
			if(!ok[it]){continue;}
			if(str[t]=='A'){A[it]--;}else{B[it]--;}
			if(A[it]==0||B[it]==0){que.push(it);ok[it]=0;}
		}
		
	}
	for(i=0;i<n;i++){if(ok[i]){cout<<"Yes"<<endl;return 0;}}
	cout<<"No"<<endl;
	return 0;
}