#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string a[10005];
int srt[10005];
long long b[10005];
long long has[10005][28];
long long v[28][10];
int ans[10005];
string ord;

bool cmp(int x, int y) {
	return b[x] < b[y];
}

void go(int *answer, int *s, int n, int lev, int t) {
	if (n <= 1) {
		if(n==1){
		//	cerr << "string: " << a[s[0]] << "(" << t << ")" << endl;
			answer[s[0]] = t;
			return;
		}
	}
//	cerr << "GO: ";
	int i, j;
/*	for(i=0;i<n;i++)
		cerr << s[i] << "[" << b[i] << "]" << ' ';
	cerr << endl;*/

	if (lev >= 26) cerr << "ERROR! TOO DEEP" << endl;
	int c = ord[lev] - 'a' + 2;
	int flag = 1;
	
	for (i = 0; i < n; i++) {
		if (has[s[i]][c]) {
			b[s[i]] += has[s[i]][c];
			flag = 0;
		}
	}
	//cerr << "FLAG= " << flag << endl;
	sort(s, s+n, cmp);
	for (i = 0; i < n; i=j) {
		for (j = i; j < n && b[s[j]] == b[s[i]]; j++);
		go(answer, s+i, j-i, lev+1, t+(has[s[i]][c]==0)-flag);
	}
}

int main(void) {
	int T, cs;
	cin.sync_with_stdio(false);
	cin >> T;
	int i, j;
	for(i=1;i<28;i++){
		v[i][0] = i;
		for(j=1;j<10;j++)
			v[i][j] = v[i][j-1] * 28LL;
	}
	for(cs=1;cs<=T;cs++){
		int m, n;
		memset(has, 0, sizeof(has));
		memset(ans, 0, sizeof(ans));
		cin >> n >> m;
		for(i=0;i<n;i++) {
			cin >> a[i];
			for(j=0;j<a[i].size();j++)
				has[i][a[i][j]-'a'+2] += v[a[i][j]-'a'+2][j] - v[1][j];
		}
		cout << "Case #" << cs << ":";
		cerr << "Case #" << cs << ":";
		while(m--) {
			cin >> ord;
			for(i=0;i<n;i++) {
				srt[i] = i;
				b[i] = 0;
				for(j=0;j<a[i].size();j++)
					b[i] += v[1][j];
			}
			sort(srt, srt+n, cmp);
			for(i=0;i<n;i=j){
				for(j=i;j<n && b[srt[i]]==b[srt[j]];j++);
				go(ans, srt+i, j-i, 0, 0);
			}
			int best=0;
			for(i=0;i<n;i++)
				if(ans[i]>ans[best])
					best = i;
			cout << " " << a[best];
			cerr << " " << a[best];
		}
		cout << endl;
		cerr << endl;
	}
	return 0;
}
