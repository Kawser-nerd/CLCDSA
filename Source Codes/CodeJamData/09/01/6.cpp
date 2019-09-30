#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

vector<vector<int> > words;
#define fu(i,m,n) for(int i=m; i<n; i++)

vector<int> parse(string& s) {
	int i=0;
	vector<int> v;
	while(i<s.size()) {
		int x=0;
		if(s[i]=='(') {
			while(s[++i]!=')') {
				x |= 1 << s[i]-'a';
			}
		}
		else {
			x |= 1 << s[i]-'a';
		}
		i++;
		v.push_back(x);
	}
	return v;
}

bool match(const vector<int>& v, const vector<int>& w) {
	assert(v.size()==w.size());
	fu(i,0,v.size()) if(v[i]&w[i]); else return false;
	return true;
}

int main(void) {
	int L,D,N;
	cin >> L >> D >> N;
	fu(d,0,D) {
		string s;
		cin >> s;
		int i=0;
		vector<int> v=parse(s);
		words.push_back(v);
		assert(v.size()==L);
	}
	fu(n,0,N) {
		string s;
		cin >> s;
		vector<int> w = parse(s);
		assert(w.size()==L);
		int cnt=0;
		fu(d,0,D) if(match(words[d],w)) cnt++;
		cout << "Case #" << n+1 << ": " << cnt << endl;
	}
}
