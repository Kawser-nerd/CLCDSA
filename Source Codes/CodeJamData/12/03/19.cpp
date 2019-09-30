#include <iostream>
#include <tr1/unordered_set>
#include <cstdlib>
using namespace std;
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		string sa,sb;cin>>sa>>sb;
		int N = sa.size();
		int z=1;
		for(int i=1; i<N; ++i) z *= 10;
		int A=atoi(sa.c_str()),B=atoi(sb.c_str());
		int r = 0;
		tr1::unordered_set<int> olds;
		for(int i=A; i<=B; ++i) {
			olds.clear();
			for(int j=0,c=i; j<N; ++j, c=c/10+z*(c%10)) {
				if (c>i && c<=B && !olds.count(c)) {
					olds.insert(c);
					++r;
				}
			}
		}
		cout<<"Case #"<<a<<": "<<r<<'\n';
	}
}
