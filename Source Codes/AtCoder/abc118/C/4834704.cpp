#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<long>A;
	int tmp;
	for(int i=0;i<N;++i){
		cin>>tmp;
		A.push_back(tmp);
	}
	sort(A.begin(),A.end(),greater<int>());
	long ans=A[0];
	while(A.size()!=1){
		/*
		for(int i=0;i<A.size();++i){
			cout<<A[i]<<" ";
		}
		cout<<endl;
		*/
		for(int i=1;i<N;++i){
			A[i]%=A[0];
		}
		sort(A.begin(),A.end(),greater<int>());
		while(A[A.size()-1]==0)A.pop_back();
		sort(A.begin(),A.end());
		if(A[0]!=0)ans=A[0];
	}
	cout<<ans<<endl;
}