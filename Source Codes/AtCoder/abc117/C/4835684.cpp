#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	vector<long>X;
	long tmp;
	for(int i=0;i<M;++i){
		cin>>tmp;
		X.push_back(tmp);
	}
	if(M>1){
		sort(X.begin(),X.end());
		vector<long>arr;
		for(int i=1;i<M;++i){
			arr.push_back(X[i]-X[i-1]);
		}
		sort(arr.begin(),arr.end());
		/*
		for(int i=0;i<M;++i){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		*/
		for(int i=0;i<N-1;++i){
			if(arr.size()>0)arr.pop_back();
		}
		cout<<accumulate(arr.begin(),arr.end(),0)<<endl;
	}
	else cout<<0<<endl;
}