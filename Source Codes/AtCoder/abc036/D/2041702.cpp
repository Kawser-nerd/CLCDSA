#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
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

struct kk{
	ll w;
	ll b;
};
 
struct kk aa(int y,list<int> li[100001],int used[100001]){
	kk answer;
	answer.w=1;
	answer.b=1;
		
		bool b = true;
		while(!li[y].empty()){
			int x = li[y].front();
			li[y].pop_front();
			if(used[x]){
				used[x]=0;
				b=false;
				kk memo = aa(x,li,used);
			
				answer.w = answer.w*(memo.b+memo.w)%MOD;
				answer.b=answer.b*memo.w%MOD;
			}

		}
		return answer;
	
}
 
int main(void){
	int n;
	cin>>n;
	int a,b;
	list<int> li[100001];
	rep(i,n-1){
		cin>>a>>b;
		li[a].push_back(b);
		li[b].push_back(a);
	}
	int used[100001];

	rep(i,100001){
		used[i]=1;

	}

	queue<int> q;
	used[1]=0;
	q.push(1);
	int y = 1;
	kk answerr;
	
	answerr = aa(1,li,used);

	cout<<(answerr.w+answerr.b)%MOD<<endl;
	return 0;
}