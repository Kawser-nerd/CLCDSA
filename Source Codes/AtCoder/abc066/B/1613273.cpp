#include<cstdio>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
	string s;cin>>s;
	bool end = true;

	REP(i,2) s.pop_back();
	while(end){
		for(int i=0,j=s.size()/2;i<s.size()/2;i++,j++){
			if(s[i]!=s[j]){
				s.pop_back();
				s.pop_back();
				break;
			}
			if(i==s.size()/2 - 1) end = false;
		}
	}
	cout << s.size() << endl;
	return 0;
}