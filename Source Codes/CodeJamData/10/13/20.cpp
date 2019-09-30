#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define fr(i, N) for(i = 0; i < (int)N; i++)
#define SZ(u) ((int)u.size())
#define setContains(i,j) (((1<<j)&i) != 0)
#define MP make_pair
#define F first
#define S second
#define pb push_back
#define Eps 1e-11

typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

inline bool isDigit(char a) { return '0' <= a && a <= '9'; }

vi Start, End;

void pre_process();
void input();
void process();

int main()
{
	int t, T;
	//scanf("%d", &T);
	cin >> T;
	pre_process();

	fr(t, T)
	{
		input();
		printf("Case #%d: ", t+1);
		process();
		fflush(stdout);
	}
	return 0;
}

void pre_process() {
	int i, N = 1000000;
	Start = vi(N+1, 0);
	End = vi(N+1, 0);
	
	Start[1] = End[1] = 1;
	
	int til = 1;
	for (i = 2; i <= N; i++) {
		while (til < i && til+1 <= N) {
			til++;
			Start[til] = i;
		}
		
		End[i] = i + Start[i] - 1;
		while (til+1 <= End[i] && til+1 <= N) {
			til++;
			Start[til] = i;
		}
	}
	
//	for (i = 1; i <= 10; i++) printf("%d %d\n", Start[i], End[i]);
}
void input() {
}
void process() {
	int i, A1, A2, B1, B2;
	ll res = 0;
	scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
	
	for (i = A1; i <= A2; i++) {
		if (B1 < Start[i]) {
			if (B2 < Start[i]) {
				res += B2 - B1 + 1;
				continue;
			}
			res += Start[i] - B1;
		}
		
		if (B2 > End[i]) {
			if (B1 > End[i]) res += B2 - B1 + 1;
			else res += B2 - End[i];
		}
	}
	
	printf("%lld\n", res);
}