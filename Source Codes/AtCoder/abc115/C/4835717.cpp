#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	long N,K;
	cin>>N>>K;
	vector<long>h;
	long tmp;
	for(int i=0;i<N;++i){
		cin>>tmp;
		h.push_back(tmp);
	}
	sort(h.begin(),h.end());
	long ans=h[h.size()-1];
	for(int i=0;i<N-(K-1);++i){
		if(ans>h[i+K-1]-h[i])ans=h[i+K-1]-h[i];
	}
	cout<<ans<<endl;
}