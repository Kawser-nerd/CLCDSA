#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;

char mood[210000];

void read() {
	scanf("%s", mood);
}

vector<char> have;

void solve() {
	n = strlen(mood);

	have.clear();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!have.empty() && mood[i] == have.back()) {
			have.pop_back();
			ans += 10;
		}
		else have.push_back(mood[i]);
	}

	ans += 5 * (have.size() / 2);
	printf("%d\n", ans);
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