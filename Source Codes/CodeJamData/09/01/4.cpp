#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

const int MAXD=5005;

int L,D,N;
string word[MAXD];

vector<set<char> > parse(string s) {
	set<char> emp;
	vector<set<char> > ret(L,emp);
	int ind=0;
	for(int i=0;i<L;i++) {
		if (s[ind]!='(') {
			ret[i].insert(s[ind]);
			ind++;
			continue;
		}	else {
			ind++;
			while (s[ind]!=')') {
				ret[i].insert(s[ind]);
				ind++;
			}
			ind++;
			continue;
		}
	}
	return ret;
}

int main() {
	cin >> L >> D >> N;
	for(int i=0;i<D;i++) {
		cin >> word[i];
	}
	for(int i=0;i<N;i++) {
		string s;
		cin >> s;
		vector<set<char> > dict=parse(s);
		int ans=0;
		for(int j=0;j<D;j++) {
			bool yes=true;
			for(int k=0;k<L;k++) {
				if (dict[k].count(word[j][k])==0) {
					yes=false;
					break;
				}
			}
			if (yes) {ans++;}
		}
		printf("Case #%d: %d\n",i+1,ans);		
	}
	return 0;
}
