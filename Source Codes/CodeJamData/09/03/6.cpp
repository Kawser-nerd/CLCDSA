#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

vector<vector<int> > words;
#define fu(i,m,n) for(int i=m; i<n; i++)

string target="welcome to code jam";

int cnt[1000][100];

int main(void) {
	int N;
	cin >> N;
	string s;
	getline(cin,s);
	fu(i,0,N) {
		//memset(cnt,0,sizeof(cnt));
		cnt[0][0]=1;
		string str;
		getline(cin,str);
		fu(s,1,str.size()+1) fu(t,0,target.size()+1) {
			cnt[s][t]=cnt[s-1][t];
			if(t>0 && str[s-1]==target[t-1]) {
				cnt[s][t]+=cnt[s-1][t-1];
				cnt[s][t]%=10000;
			}
		}
		cout << "Case #" << i+1 << ": ";
		printf("%04d\n",cnt[str.size()][target.size()]);
	}
}
