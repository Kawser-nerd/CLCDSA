#include <stdio.h>
#include <algorithm>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int time = 0;
	while ((A % 2 == 0 && B % 2 == 0 && C % 2 == 0) && !(A == B && B == C && C == A)) {
		time++;
		int TA = (B + C) / 2;
		int TB = (A + C) / 2;
		int TC = (A + B) / 2;
		A = TA;
		B = TB;
		C = TC;
	}
	if (A == B && B == C && C == A && A % 2 == 0)
		printf("%d\n", -1);
	else
		printf("%d\n",time);
}