#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int T, P, K, L;
vector<int> F;

typedef long long ll;

int main(){
	ifstream cin("a2.in");
	ofstream cout("a2.out");
	
	cin>>T;
	for (int Case=1; Case<=T; ++Case){
		cin>>P>>K>>L;
		
		for (int i=0;i<L;++i){
			int j;
			cin>>j;
			F.push_back(j);
		}
		
		sort(F.begin(), F.end(), greater<int>());
		
		ll ret = 0;
		int j=0;
		for (int i=1;i<=P;++i){
			for (int r=0;r<K;++r){
				if (j<L){
					ret += ll(i)*F[j++];
				}
				else break;
			}
			if (j>=L) break;
		}
		
		
		cout<<"Case #"<<Case<<": ";
		if (L > P*K){
			cout<<"Impossible"<<endl;
		}
		else{
			cout<<ret<<endl;
		}
		
		F.clear();
	}
	
	return 0;
}
