#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;
using ull = unsigned long long;
int M = 1e9 + 7;

ll modpow(ll b, ll p, ll m) {
	ll ret = 1;
	while(p){
		if(p & 1){
			ret = ret * b % m;
		}
		p >>= 1;
		b = b * b % m;
	}
	return ret;
}

//TODO base 1 is special!!!
struct BaseN{
	ll digits, base;
	long double coefficient;
	vector<ll> nsDigits;
	BaseN(ll num, ll base): digits(0), base(base), coefficient(num){
		if(base == 1){
			digits = num;
			return;
		}
		while(num >= base){
			nsDigits.push_back(num % base);
			num /= base;
			coefficient /= base;
		}
		digits = nsDigits.size();
		nsDigits.push_back(num);
	}

	//for assending
	bool operator < (const BaseN& n) const{
		return !(
			digits < n.digits ? true :
			digits > n.digits ? false :
			coefficient < n.coefficient);
	}

	ll getNum() const{
		if(base == 1){
			return digits;
		}
		ll ret = 0;
		for(ll i=nsDigits.size()-1;i>=0;i--){
			ret = (ret * base + nsDigits[i]) % M;
		}
		ret = ret * modpow(base, digits - nsDigits.size() + 1, M) % M;
		return ret;
	}
};

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a == 1){
		b = 0;
	}
	priority_queue<BaseN> pq;
	for(int i=0;i<n;i++){
		int ai;
		cin >> ai;
		BaseN n(ai, a);
		pq.push(n);
	}

	int under = b / n - 10;
	{
		priority_queue<BaseN> tmp;
		while(!pq.empty()){
			BaseN n = pq.top();
			pq.pop();
			if(n.digits < under){
				b -= under - n.digits;
				n.digits = under;
			}
// 			cout<<"push "<<n.getNum(a)<<endl;
			tmp.push(n);
		}
		tmp.swap(pq);
	}

// 	cout<<b<<endl;
	for(int i=0;i<b;i++){
		BaseN n = pq.top();
		pq.pop();
// 		cout<<"get "<<n.getNum(a)<<endl;
		n.digits++;
		pq.push(n);
// 		cout<<"push "<<n.getNum(a)<<endl;
	}

	while(!pq.empty()){
		BaseN n = pq.top();
		pq.pop();
		cout << n.getNum() << endl;
	}

	return 0;
}