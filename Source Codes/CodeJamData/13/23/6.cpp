#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 600000;

int ntest;
vector<string> w[11];
string s;
int n, m;
int dp[5000][5];

fstream fin("garbled_email_dictionary.txt");

int main() {
	
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	while(fin>>s) {
		w[s.length()].push_back(s);
	}

	cin>>ntest;
	for(int test = 1; test <= ntest; test++) {
		cin>>s;
		m = s.length();

		memset(dp, 0x3f, sizeof(dp));
		dp[0][4] = 0;
		
		for(int i=0; i<m; i++) {
			cerr<<test<<" "<<i<<endl;
			for(int j=0; j<5; j++) {

				if(dp[i][j] > 5000) continue;

				for(int l=1; l<=10 && i+l<=m; l++) {
					string tt = s.substr(i, l);
					const char *t = tt.c_str();

					for(vector<string>::iterator it = w[l].begin(); it != w[l].end(); it++) {
						int now = j;
						string xx = *it;
						const char *x = xx.c_str();
						bool ok = true;
						int cnt = 0;
						for(int k=0; k<l; k++) {
							if(t[k] == x[k]) {
								now++;
							} else {
								cnt++;
								if(now < 4) {
									ok = false;
									break;
								} else {
									now = 0;
								}
							}
						}
						if(ok) {
							if(now > 4) now = 4;

							dp[i+l][now] = min(dp[i+l][now], dp[i][j] + cnt);
						}
					}
				}

			}
		}

		int answer = 5000;
		for(int j=0; j<5; j++) answer = min(answer, dp[m][j]);
		printf("Case #%d: %d\n", test, answer);
	}
	return 0;
}
