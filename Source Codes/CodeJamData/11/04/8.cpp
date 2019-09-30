#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int tnum;cin>>tnum;
	int tcou=0;
	while (tnum--){
		int n;cin>>n;
		vector<int> v(n);
		for (int i=0;i<n;++i)
			cin>>v[i];
		vector<int> s=v;
		sort(s.begin(),s.end());
		int ans=0;
		for (int i=0;i<n;++i)
			if (v[i]!=s[i])
				++ans;
		cout<<"Case #"<<++tcou<<": "<<ans<<endl;
	}
	return 0;
}
