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
using namespace std;
typedef long long int llint;
typedef long double lld;
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
#define dme cout<<"-1"<<endl;return 0
const int mod=1000000007;
const int big=1e9+10;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
//19:04~
int main(void){
	int A,B,C,D,E,F;
	cin>>A>>B>>C>>D>>E>>F;
	int mizu[31]={0};//?
	int sato[3001]={0};//???
	for(int i=0;i<=30;i++){
		for(int j=0;j<=30;j++){
			if(A*i+B*j>30){break;}
			mizu[A*i+B*j]=1;
		}
	}
	for(int i=0;i<=3000;i++){
		for(int j=0;j<=3000;j++){
			if(C*i+D*j>3000){break;}
			sato[C*i+D*j]=1;
		}
	}
	int ans=100*A,ansa=0;//??,??
	for(int i=1;i<=30;i++){
		for(int j=0;j<=3000;j++){
			if(i*100+j>F){break;}
			if(i*E<j){break;}
			if(mizu[i]==0){break;}
			if(sato[j]==0){continue;}
			if(((double)ansa)/ans<((double)j)/(i*100+j)){
				ans=i*100+j;ansa=j;
			}
		}
	}
	cout<<ans<<" "<<ansa<<endl;
	return 0;
}