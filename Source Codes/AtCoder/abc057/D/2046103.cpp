#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <queue>
#include <cstdlib>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
//#define ARRAY(type,n) (type *)malloc(sizeof(type)*n)
template<typename T>
T* ARRAY(int n){
	(T*)malloc(sizeof(T)*n);
}
template<typename T>
T** ARRAY2(int m,int n){
	T** type = (T**)malloc(sizeof(T*)*m);
	for(int i=0;i<m;i++){
		type[i]=(T*)malloc(sizeof(T)*n);
	}
	return type;
}
class llm{
public:
llm(ll value){this->value = (ll)value;}
ll value;
llm operator + (llm obj){return llm((this->value + (ll)(obj.value))%MOD);}
llm operator + (ll obj){return llm((this->value + obj)%MOD);}
llm operator - (llm obj){return llm(((this->value + MOD - (ll)(obj.value)))%MOD);}
llm operator - (ll obj){return llm(((this->value + MOD - obj))%MOD);}
llm operator * (llm obj){return llm((this->value * (ll)(obj.value))%MOD);}
llm operator * (ll obj){return llm((this->value * obj)%MOD);}
llm operator / (llm obj){return llm(this->value / (ll)(obj.value));}
llm operator / (ll obj){return llm(this->value / obj);}
llm operator % (llm obj){return llm(this->value % (ll)(obj.value));}
llm operator % (ll obj){return llm(this->value % obj);}};
ostream& operator<<(ostream& os, llm l){os << l.value;return os;} 
llm operator+(ll a,llm l){return llm((a + l.value)%MOD);} 
llm operator*(ll a,llm l){return llm((a * l.value)%MOD);}

ll c[53][53];

ll C(int n,int k){
	if(c[n][k]!=-1){
		return c[n][k];
	}else if(n==k){
		c[n][k] = 1;
		return 1;
	}
	
	c[n][k] = C(n-1,k)*n/(n-k);
	//cout<<n<<" "<<k<<" "<<c[n][k]<<endl;
	return c[n][k];
}



int main(void){
	rep(i,53){
		rep(j,53){
			c[i][j]=-1;
		}
	}
	int n,a,b;
	cin>>n>>a>>b;
	ll v[n];
	rep(i,n){
		cin>>v[i];
	}

	sort(v,v+n);
	reverse(v,v+n);

	ll memo=v[a-1];
	int count = 0;
	ll ans2 = 0;
	rep(i,a){
		if(memo==v[i]){
			count++;
		}
		ans2+=v[i];
	}

	int count2 = 0;
	
	rep(i,n){
		if(memo==v[i]){
			count2++;
		}

	}

	
	ll ans = 0;
	if(count == a){
		for(int i=a;i<=min(b,count2);i++){
			ans += C(count2,i);
		}
	}else{
		ans += C(count2,count);
	}




	cout<<fixed;
	cout<<(double)ans2/a<<endl;
	cout<<ans<<endl;
	return 0;
}