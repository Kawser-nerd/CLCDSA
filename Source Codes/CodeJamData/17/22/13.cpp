/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

string ans;

bool sub2( int a, int b, char A, char B ) {
	string tmp;
	tmp += A, tmp += B;
	ans = "";
	forn(i, a)
		ans += tmp;
	return a == b;
}

bool solve() {
	int N, R, O, Y, G, B, V;
	scanf("%d%d%d%d%d%d%d", &N, &R, &O, &Y, &G, &B, &V);
	if (N == O + B) return sub2(O, B, 'O', 'B');
	if (N == G + R) return sub2(G, R, 'G', 'R');
	if (N == V + Y) return sub2(V, Y, 'V', 'Y');
	if ((O && O >= B) || (G && G >= R) || (V && V >= Y)) return 0;
	B -= O, R -= G, Y -= V;
	// printf("[...] %d %d %d ", B, R, Y);
	if (B > R + Y || R > B + Y || Y > R + B)
		return 0;
	ans = "";
	int last = -1, first = -1;
	N = B + R + Y;
	while (B || R || Y) {
		int letter = -1, *cnt = 0;
		N--;
		if (last != 'B' && (letter == -1 || B > *cnt || (B == *cnt && first == 'B'))) letter = 'B', cnt = &B;
		if (last != 'R' && (letter == -1 || R > *cnt || (R == *cnt && first == 'R'))) letter = 'R', cnt = &R;
		if (last != 'Y' && (letter == -1 || Y > *cnt || (Y == *cnt && first == 'Y'))) letter = 'Y', cnt = &Y;
		assert(letter != -1);
		assert(*cnt > 0);
		last = letter;
		ans += (char)letter;
		// printf("%c ", letter);
		if (letter == 'B') while (O > 0) ans += "OB", O--;
		if (letter == 'R') while (G > 0) ans += "GR", G--;
		if (letter == 'Y') while (V > 0) ans += "VY", V--;
		*cnt -= 1;
		if (first == -1)
			first = last;
	}
	return 1;
}

int main() {
	int tn;
	scanf("%d", &tn);
	for (int t = 1; t <= tn; t++) {
		printf("Case #%d: ", t);
		fprintf(stderr, "Case #%d\n", t);
		if (!solve())
			puts("IMPOSSIBLE");
		else
			puts(ans.c_str());
	}
}