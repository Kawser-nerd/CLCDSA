#include<cstdio>
#include<iostream>

//STL
#include<string>
#include<vector>
#include<map>

//sort??reverse
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	char** s;
	s = new char*[n];
	for(int i=0;i<n;++i)
		s[i] = new char[n];

	for(int i=0;i<n;++i){
		for(int j=0; j<n; ++j){
			cin>>s[i][j];
		}
	}
	char** ans;
	ans = new char*[n];
	for(int i=0; i<n;++i)
		ans[i] = new char[n];

	for(int i=0;i<n;++i){
		for(int j=0; j<n; ++j){
			ans[i][j] = s[(n-1)-j][i];
			cout<<ans[i][j];
		}
		cout<<endl;
	}

	return 0;
}