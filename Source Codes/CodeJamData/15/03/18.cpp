#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cloj[24][24];
int rep[24][24];
int tmp[24][24];
char dat[1000003];
int trans[4][24][24];

const int quaternion_multiplication[4][4]=
{
	0, 1, 2, 3,
	1, 4, 3, 6,
	2, 7, 4, 1,
	3, 2, 5, 4
};

int multiply(int a, int b) {
	int neg = 0;
	if (a >= 4) {neg ^= 1; a -= 4;}
	if (b >= 4) {neg ^= 1; b -= 4;}
	return (quaternion_multiplication[a][b] + neg*4)%8;
}

void matmul(int dest[24][24], int mul[24][24]) {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 24; j++) {
			int station = dest[j][i];
			for (int k = 0; k < 24; k++) {
				tmp[j][k] |= (station && mul[i][k]);
			}
		}
	}
	memcpy(dest, tmp, sizeof(tmp));
}

int main() {
	int T;
	scanf("%d",&T);
	for (int cur = 1; cur <= 3; cur++) {
		for (int row = 0; row < 24; row++) {
			int index = row / 8;
			int pre = row % 8;
			int next = multiply(pre, cur);
			trans[cur][row][8*index + next] = 1;
			if ((index == 0 && next == 1) ||
				(index == 1 && next == 2)) {
				trans[cur][row][8*(index+1)+0] = 1;
			}
		}
	}
	for (int testcase = 1; testcase <= T; testcase++) {
		bool ans = false;
		int L;
		long long X;
		scanf("%d%lld",&L,&X);
		scanf("%s",dat);
		memset(cloj,0,sizeof(cloj));
		memset(rep,0,sizeof(rep));
		for (int i = 0; i < 24; i++) {
			cloj[i][i] = 1;
			rep[i][i] = 1;
		}
		for (int i = 0; i < L; i++) {
			int cur = dat[i] - 'i' + 1;
			matmul(cloj, trans[cur]);
		}
		while(X) {
			if (X & 1) {
				matmul(rep, cloj);
			}
			matmul(cloj, cloj);
			X >>= 1;
		}

		ans = rep[0][2*8+3];
		printf("Case #%d: %s\n", testcase, ans ? "YES" : "NO");
	}
}