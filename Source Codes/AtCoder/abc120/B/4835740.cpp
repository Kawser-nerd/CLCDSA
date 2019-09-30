#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int A,B,K;
	cin>>A>>B>>K;
	vector<int>arr;
	for(int i=1;i<=min(A,B);++i){
		if(A%i==0 && B%i==0)arr.push_back(i);
	}
	cout<<arr[arr.size()-K]<<endl;
}