#include <iostream>
#include <cstring>
using namespace std;
const char* enc = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char* orig = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

char mp[256];

int main() {
	int N = strlen(enc);
	for(int i=0; i<N; ++i) mp[enc[i]] = orig[i];
	mp['q'] = 'z';
	mp['z'] = 'q';

	int t;cin>>t;
	cin.ignore();
	for(int a=1; a<=t; ++a) {
		string s;
		getline(cin,s);
		for(size_t i=0; i<s.size(); ++i) s[i]=mp[s[i]];
		cout<<"Case #"<<a<<": "<<s<<'\n';
	}
}
