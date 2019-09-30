#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#define IT 10000

int n,m;

//calcula função de transição 
void func(char *p, int m, int *pos){ int i, j=-1; pos[0]=-1; for( i=1 ; i<m ; i++ ){ while( j>=0 && p[j+1]!=p[i] ) j=pos[j]; if( p[j+1]==p[i] ) j++; pos[i]=j; } } 
//acha posições 
bool kmp(const char *t, int n, char *p, int m, int *pos){ int i, j=-1; for( i=0 ; i<n ; i++ ){ while( j>=0 && t[i]!=p[j+1] ) j=pos[j]; if( t[i]==p[j+1] ) j++; if( j==m-1 ){ return true; j=pos[j]; } } return false;}

int prereq[250];
char let[250];
char cool[6][30];
int pos[6][30];

void read() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &prereq[i]);
	REP(i,n) scanf(" %c", &let[i]);
	scanf("%d", &m);
	REP(i,m) scanf("%s", cool[i]);
}

string t;
vector<int> clears[110];
int cnt[6];

typedef std::mt19937 G;
G g;
typedef std::uniform_int_distribution<> D;

string interleave(const string& a, const string& b) {
	string ret = "";
	int aI = 0, bI = 0;

	while (aI < a.size() || bI < b.size()) {
		D d(1, a.size()-aI + b.size()-bI);
		int nxt = d(g);
		if (nxt <= (a.size()-aI)) {
			ret += a[aI++];
		}
		else ret += b[bI++]; 
	}

	return ret;
}

string rec(int v) {
	string k = ""; k += let[v];
	string ot = "";
	for (int x: clears[v]) {
		ot = interleave(ot, rec(x));
	}

	return k + ot;
}

void solve() {
	REP(i,m) {
		cnt[i] = 0;
		func(cool[i], strlen(cool[i]), pos[i]);
	}

	REP(i,n) clears[i].clear();
	REP(i,n) {
		if (prereq[i] != 0) {
			clears[prereq[i]-1].push_back(i);
		}
	}

	string cur;

	for (int it = 0; it < IT; it++) {
		cur = "";
		REP(i,n) if (prereq[i] == 0) {
			cur = interleave(cur, rec(i));
		}

		//printf("cur = %s\n", cur.c_str());
		
		REP(i, m) cnt[i] += kmp(cur.c_str(), n, cool[i], strlen(cool[i]), pos[i]);
	}

	REP(i,m) printf("%.10f ", ((double)cnt[i]) / IT);
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
			fprintf(stderr, "proc case %d\n", i+1);
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}