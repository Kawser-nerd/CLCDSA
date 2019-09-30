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
 

struct a{
	int i;
	int j;
	int n;

	bool operator<( const a& right ) const {
        return n < right.n;
    }
};
 
int main(void){
	int h,w;
	cin>>h>>w;
	a b[h*w];
	ll ans[(h+2)][w+2];
	int memo[(h+2)][w+2];
	rep(i,h){
		rep(j,w){
			ans[i+1][j+1]=1;
			b[i*w+j].i=i+1;
			b[i*w+j].j=j+1;
			cin>>b[i*w+j].n;
			memo[i+1][j+1]=b[i*w+j].n;
		}
	}

	rep(i,h+2){
		ans[i][0]=0;
		ans[i][w+1]=0;
	}
	rep(i,w+2){
		ans[0][i]=0;
		ans[h+1][i]=0;
	}

	sort(b,b+h*w);
	ans[1][1]=1;
	rep(i,h*w){
		if(memo[b[i].i-1][b[i].j]>memo[b[i].i][b[i].j])
		ans[b[i].i-1][b[i].j]=(ans[b[i].i-1][b[i].j]+ans[b[i].i][b[i].j])%MOD;
		
		if(memo[b[i].i+1][b[i].j]>memo[b[i].i][b[i].j])
		ans[b[i].i+1][b[i].j]=(ans[b[i].i+1][b[i].j]+ans[b[i].i][b[i].j])%MOD;
		
		if(memo[b[i].i][b[i].j-1]>memo[b[i].i][b[i].j])
		ans[b[i].i][b[i].j-1]=(ans[b[i].i][b[i].j-1]+ans[b[i].i][b[i].j])%MOD;
		
		if(memo[b[i].i][b[i].j+1]>memo[b[i].i][b[i].j])
		ans[b[i].i][b[i].j+1]=(ans[b[i].i][b[i].j+1]+ans[b[i].i][b[i].j])%MOD;
	}
	ll answer=0;
	rep(i,h){
		rep(j,w){
			answer = (answer + ans[i+1][j+1]) %MOD;
		}
	}
	cout<<answer<<endl;
	return 0;
}