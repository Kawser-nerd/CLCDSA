#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <queue>
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
 


 
int main(void){
	int n,a,b;
	cin>>n>>a>>b;
	cout<<(n*a<b?n*a:b)<<endl;
	return 0;
}