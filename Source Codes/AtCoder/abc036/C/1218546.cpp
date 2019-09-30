#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int N,a;
	cin >> N;
	map<int,int> mp;
	vector<int> vec;
	int r[N];
	for(int i=0;i<N;i++){
		cin >> a;
		vec.push_back(a);
		r[i]=a;
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int j=0;j<vec.size();j++){
		mp[vec[j]] = j;
	}
	for(int k=0;k<N;k++){
		cout << mp[r[k]] << endl;
	}

	return 0;
}