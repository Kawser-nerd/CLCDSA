#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n,l;
char good[110][60];
char bad[60];

void read() {
	scanf("%d %d", &n, &l);
	REP(i,n) scanf("%s", good[i]);
	scanf("%s", bad);
}

char no(char c) {
	return '0' + (!(c-'0'));
}

void solve() {
	REP(i,n) {
		if (strcmp(good[i], bad) == 0) {
			printf("IMPOSSIBLE\n");
			return;
		}
	}

	REP(i,l) {
		printf("%c", no(bad[i]));
		if (i != l-1) printf("%c", bad[i]);
	}
	printf(" ");
	REP(i,l) {
		printf("%c", no(bad[i]));
		printf("?");
	}
	printf("\n");
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}