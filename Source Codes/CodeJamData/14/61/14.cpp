#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int t, teste;

int n, cnt;
int mat[3000][3000];
int temp[3000][3000];
int temp2[3000][3000];

void swap_row(int i, int j) {
	for (int k = 0; k < n; k++) {
		swap(temp[k][i], temp[k][j]);
	}
}

void swap_col(int i, int j) {
	for (int k = 0; k < n; k++) {
		swap(temp[i][k], temp[j][k]);
	}
}

void row_pass(bool is_true) {
	for (int i = 0; i < n; i++) {
		if (temp[0][i] != (is_true ^(i&1))) {
			for (int j = i+1; j < n; j+=2) {
				if (temp[0][j] != (is_true ^ (j&1))) {
					swap_row(i, j);
					cnt++;
					break;
				}
			}
		}
	}
}

void col_pass(bool is_true) {
	for (int i = 0; i < n; i++) {
		if (temp[i][0] != (is_true ^(i&1))) {
			for (int j = i+1; j < n; j+=2) {
				if (temp[j][0] != (is_true ^ (j&1))) {
					swap_col(i, j);
					cnt++;
					break;
				}
			}
		}
	}
}

bool is_check() {
	bool f = temp[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (f != temp[i][j] ^ ((i+j)&1) ) return false;
		}
	}
	return true;
}

int main() {
	for (scanf("%d", &t); t; t--) {
		printf("Case #%d: ", ++teste);
		
		scanf("%d", &n);
		n *= 2;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %c", &mat[i][j]);
				mat[i][j] -= '0';
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp[i][j] = mat[i][j];
		}

		int best = 1000000000;
		cnt = 0;

		row_pass(true);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp2[i][j]=temp[i][j];
		}

		int cnt2 = cnt;
		col_pass(true);

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", temp[i][j]);
			}
			printf("\n");
		}*/

		if (is_check()) {best = min(best, cnt);}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp[i][j]=temp2[i][j];
		}

		cnt = cnt2;
		col_pass(false);

		if (is_check()) {best = min(best, cnt);}





		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp[i][j]=mat[i][j];
		}

		cnt = 0;

		row_pass(false);

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", temp[i][j]);
			}
			printf("\n");
		}*/

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp2[i][j]=temp[i][j];
		}

		cnt2 = cnt;
		col_pass(true);

		if (is_check()) {best = min(best, cnt);}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) temp[i][j]=temp2[i][j];
		}

		cnt = cnt2;
		col_pass(false);

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", temp[i][j]);
			}
			printf("\n");
		}*/
		if (is_check()) {best = min(best, cnt);}




		if (best == 1000000000) printf("IMPOSSIBLE\n");
		else printf("%d\n", best);
	}

    return 0;
}