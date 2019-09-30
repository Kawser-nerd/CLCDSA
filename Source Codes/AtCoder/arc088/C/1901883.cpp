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
#include<unordered_map>
#include<array>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
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
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;
const int big=1e9+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint tensort(vector<llint>& in){
	//????????????????
	llint ans=0;
	llint i,j,n=in.size(),gen=1;
	vector<llint>iti(n);
	for(gen=1;gen<n;gen*=2){
		llint now=0;
		for(i=0;i<n;i+=gen*2){//i,i+gen
			llint hid=i,mig=i+gen,end=min(n,i+gen+gen);
			if(n<=i+gen){for(j=i;j<n;j++){iti[j]=in[j];}continue;}
			while(now!=end){
				if(mig==end){iti[now]=in[hid];now++;hid++;}//?
				else if(hid==i+gen){iti[now]=in[mig];now++;mig++;}//?
				else if(in[hid]<in[mig]){iti[now]=in[hid];now++;hid++;}//?
				else{ans+=i+gen-hid;iti[now]=in[mig];now++;mig++;}//?
			}
		}
		swap(in,iti);
	}
	return ans;
}
int main(void){
	string str;cin>>str;
	array<llint,26> mzi={0};
	array<llint,26> cou={0};
	char man='!';
	llint n,i,ans=0;n=str.size();
	for(i=0;i<n;i++){mzi[str[i]-'a']++;}
	for(i=0;i<26;i++){
		if(mzi[i]%2==1){
			if(man=='!'){man='a'+i;}
			else{cout<<"-1"<<endl;RE;}//???
		}
	}
	string hid;
	string mig;
	//?????????????
	
	for(i=0;i<n;i++){
		char c=str[i]-'a';
		if(2*cou[c]+1<mzi[c]){ans+=i-(llint)hid.size();hid.pub(c+'a');}
		else{ans+=n/2 +(llint)mig.size()-i;mig.pub(c+'a');}
		cou[c]++;
	}
	reverse(hid.begin(),hid.end());
	ans/=2;
	vector<llint> in(mig.size());
	deque<llint> alf[26];
	if(man!='!'){alf[man-'a'].pub(-1);}
	for(i=0;i<hid.size();i++){
		char c=hid[i]-'a';
		alf[c].pub(i);
	}
	for(i=0;i<mig.size();i++){
		char c=mig[i]-'a';
		in[i]=alf[c].front();
		alf[c].pof();
	}
	ans+=tensort(in);
	cout<<ans<<endl;
	RE;
}