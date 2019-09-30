#include <vector>
#include <stdio.h>
using namespace std;

int n;

struct Str {
	char s[4];
};

int encode(const Str &s) {
	int res = 0;
	for (int i=0; i<n; i++)
		res = 26*res + s.s[i]-'a';
	return res;
}

void generate(vector<Str> &res, Str &str, int i, const char *row) {
	if (i>=n) {
		res.push_back(str);
		return;
	}
	char start = i==0 ? 'a' : str.s[i-1];
	for (str.s[i]=start; str.s[i]<='z'; str.s[i]++)
		if (row[i]=='.' || row[i]==str.s[i])
			generate(res, str, i+1, row);
}
void generate(vector<Str> &res, const char *row) {
	Str tmp;
	res.clear();
	generate(res, tmp, 0, row);
}

void generateSmaller(vector<Str> &res, const Str &larger, Str &str, int i, const char *row) {
	if (i>=n) {
		res.push_back(str);
		return;
	}
	char start = i==0 ? 'a' : str.s[i-1];
	for (str.s[i]=start; str.s[i]<=larger.s[i]; str.s[i]++)
		if (row[i]=='.' || row[i]==str.s[i])
			generateSmaller(res, larger, str, i+1, row);
}
void generateSmaller(vector<Str> &res, const Str &larger, const char *row) {
	Str tmp;
	res.clear();
	generateSmaller(res, larger, tmp, 0, row);
}

int buf[6][1<<19];

char grid[4][8];
int R;

vector<Str> cur, last;

int run() {
	for (int i=0; i<(1<<19); i++)
		buf[0][i] = 0;
	generate(cur, grid[0]);
	for (unsigned int i=0; i<cur.size(); i++)
		buf[0][encode(cur[i])] = 1;
	for (int row=1; row<R; row++) {
		for (int i=0; i<(1<<19); i++)
			buf[row][i] = 0;
		generate(cur, grid[row]);
		for (unsigned int i=0; i<cur.size(); i++) {
			int code = encode(cur[i]);
			generateSmaller(last, cur[i], grid[row-1]);
			for (unsigned int j=0; j<last.size(); j++) {
				int lastCode = encode(last[j]);
				buf[row][code] = (buf[row][code] + buf[row-1][lastCode]) % 10007;
			}
		}
		//printf("%d\n", row);
	}
	int res = 0;
	for (int i=0; i<(1<<19); i++)
		res = (res + buf[R-1][i]) % 10007;
	return res;
}

int main() {
	int T;
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%d%d", &R, &n);
		gets(grid[0]);
		for (int row=0; row<R; row++)
			gets(grid[row]);
		printf("Case #%d: %d\n", t, run());
		fflush(stdout);
	}
	return 0;
}
