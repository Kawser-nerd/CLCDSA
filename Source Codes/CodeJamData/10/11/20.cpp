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

int N, K;
vvi List;

void pre_process();
void input();
void process();
vvi clockRotate(vvi);
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int main()
{
	int t, T;
	scanf("%d", &T);
	//cin >> T;
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
}
void input() {
	int i, j;
	char a;
	scanf("%d%d", &N, &K);
	List = vvi(N, vi(N, 0));
	
	fr (i, N) fr (j, N) {
		scanf("%c", &a);
		if (a != '.' && a != 'R' && a != 'B') {
			j--;
			continue;
		}
		
		if (a == '.') continue;
		if (a == 'R') List[i][j] = 1;
		else List[i][j] = 2;
	}
}
void process() {
	int i, j, k, l;
	bool red = false, blue = false;
	int dr[4] = {1, 0, 1, 1};
	int dc[4] = {0, 1, -1, 1};
	
	vvi A = clockRotate(List);
	fr (j, N) {
		int move = N-1;
		for (i = N-1; i >= 0; i--) if (A[i][j] != 0) {
			int temp = A[i][j];
			A[i][j] = 0;
			A[move--][j] = temp;
		}
	}
	/*
	fr (i, N) {
		fr (j, N) printf("%d", A[i][j]);
		printf("\n");
	}*/
	
	fr (i, N) fr (j, N) if (A[i][j] != 0) {
		fr (k, 4) {
			for (l = 0; isValid(i+l*dr[k], j+l*dc[k]); l++) if (A[i+l*dr[k]][j+l*dc[k]] != A[i][j]) break;
			
			if (l >= K) {
				if (A[i][j] == 1) red = true;
				else blue = true;
			}
		}
	}
	
	if (red && blue) printf("Both\n");
	else if (red) printf("Red\n");
	else if (blue) printf("Blue\n");
	else printf("Neither\n");
}

vvi clockRotate(vvi A) {
    vvi res;
    int i, j;
    fr (i, A[0].size()) res.pb(vi(A.size(), 0)); // to generate the same size

    fr (i, A.size()) fr (j, A[i].size()) res[j][A.size()-i-1] = A[i][j];

    return res;
  }