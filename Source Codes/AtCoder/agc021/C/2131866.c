#include <stdio.h>
#include <stdlib.h>

int N, M, A, B;
char result[1024][1024];

void init(void) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) result[i][j] = '.';
	}
}

void success(void) {
	int i;
	puts("YES");
	for (i = 0; i < N; i++) puts(result[i]);
	exit(0);
}

void try1(int mode) {
	int i, j, Aleft = A, Bleft = B;
	init();
	for (j = 0; j < M && Bleft > 0; j += 2) {
		for (i = 0; i + 1 < N && Bleft > 0; i += 2) {
			result[i][j] = '^';
			result[i + 1][j] = 'v';
			Bleft--;
			if (Bleft > 0 && j + 1 < M && result[i][j+1] == '.' && result[i + 1][j + 1] == '.' &&
			(M % 2 == mode || j > 0)) {
				result[i][j + 1] = '^';
				result[i + 1][j + 1] = 'v';
				Bleft--;
			}
		}
		if (M % 2 != mode && j == 0) j--;
	}
	if (Bleft > 0) return;
	for (i = 0; i < N && Aleft > 0; i++) {
		for (j = M - 2; j >= 0 && result[i][j] == '.' && Aleft > 0; j -= 2) {
			result[i][j] = '<';
			result[i][j + 1] = '>';
			Aleft--;
		}
	}
	if (Aleft > 0) return;
	success();
}

/*
(mode = 0)
3 3 2 2
*/
void try2(int mode) {
	int i, j, Aleft = A, Bleft = B;
	init();
	if (Bleft > 0 && N >= 2) {
		result[N - 2][M - 1] = '^';
		result[N - 1][M - 1] = 'v';
		Bleft--;
	}
	for (j = 0; j < M && Bleft > 0; j += 2) {
		for (i = 0; i + 1 < N && result[i][j] == '.' && result[i + 1][j] == '.' && Bleft > 0; i += 2) {
			result[i][j] = '^';
			result[i + 1][j] = 'v';
			Bleft--;
			if (Bleft > 0 && j + 1 < M && result[i][j+1] == '.' && result[i + 1][j + 1] == '.' &&
			(M % 2 == mode || j > 0)) {
				result[i][j + 1] = '^';
				result[i + 1][j + 1] = 'v';
				Bleft--;
			}
		}
		if (M % 2 != mode && j == 0) j--;
	}
	if (Bleft > 0) return;
	for (i = 0; i < N && Aleft > 0; i++) {
		for (j = result[i][M - 1] == '.' ? M - 2 : M - 3; j >= 0 && result[i][j] == '.' && Aleft > 0; j -= 2) {
			result[i][j] = '<';
			result[i][j + 1] = '>';
			Aleft--;
		}
	}
	if (Aleft > 0) return;
	success();
}

void try3(int mode) {
	int i, j, Aleft = A, Bleft = B;
	init();
	if (Aleft > 0 && M >= 2) {
		result[0][0] = '<';
		result[0][1] = '>';
		Aleft--;
	}
	for (j = 0; j < M && Bleft > 0; j += 2) {
		for (i = result[0][j] == '.' ? 0 : 1; i + 1 < N && result[i][j] == '.' && result[i + 1][j] == '.' && Bleft > 0; i += 2) {
			result[i][j] = '^';
			result[i + 1][j] = 'v';
			Bleft--;
			if (Bleft > 0 && j + 1 < M && result[i][j+1] == '.' && result[i + 1][j + 1] == '.' &&
			(M % 2 == mode || j > 0)) {
				result[i][j + 1] = '^';
				result[i + 1][j + 1] = 'v';
				Bleft--;
			}
		}
		if (M % 2 != mode && j == 0) j--;
	}
	if (Bleft > 0) return;
	for (i = 0; i < N && Aleft > 0; i++) {
		for (j = result[i][M - 1] == '.' ? M - 2 : M - 3; j >= 0 && result[i][j] == '.' && Aleft > 0; j -= 2) {
			result[i][j] = '<';
			result[i][j + 1] = '>';
			Aleft--;
		}
	}
	if (Aleft > 0) return;
	success();
}

int main(void) {
	if (scanf("%d%d%d%d", &N, &M, &A, &B) != 4) return 1;
	try1(0);
	try2(0);
	try3(0);
	try1(1);
	try2(1);
	try3(1);
	puts("NO");
	return 0;
}

/*
7 7 2 22

YES
^^^^^^^
vvvvvvv
^^^^^^^
vvvvvvv
^^^^^^^
vvvvvvv
..<><>v

invalid (overlap)

*/