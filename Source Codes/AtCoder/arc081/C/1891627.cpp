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
const llint big=1e15+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
int main(void){
	string str;cin>>str;
	int n,i,j,c;n=str.size();
	reverse(str.begin(),str.end());
	vector<int>naga(n);
	//?????????????????
	array<bool,26> aru={0};
	int arucou=0;
	int gen=1;
	for(i=0;i<n;i++){
		if(!aru[str[i]-'a']){arucou++;}
		aru[str[i]-'a']=true;
		naga[i]=gen;
		if(arucou==26){
			arucou=0;gen++;
			for(c=0;c<26;c++){aru[c]=false;}
		}
	}
	reverse(str.begin(),str.end());
	reverse(naga.begin(),naga.end());
	string ans;
	char moku='!';
	for(i=0;i<n;i++){
		if(gen>naga[i]){
			//?????????????
			for(c='a';c<='z';c++){if(!aru[c-'a']){moku=c;break;}}
			for(c='a';c<='z';c++){aru[c-'a']=false;}
			gen--;
		}
		if(moku=='!'){aru[str[i]-'a']=true;}
		if(moku==str[i]){ans.pub(moku);moku='!';}
	}
	for(c='a';c<='z';c++){if(!aru[c-'a']){moku=c;break;}}
	for(c='a';c<='z';c++){aru[c-'a']=false;}
	ans.pub(moku);
	cout<<ans<<endl;
}