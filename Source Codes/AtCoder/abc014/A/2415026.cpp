#include<algorithm>
#include<iostream>
#include<math.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<string>
#include<vector>

using namespace std;
int main(void) {
	int A = 0, B = 0;
	scanf("%d%d", &A, &B);
	printf("%d\n", A % B != 0 ? (B - (A % B)) : 0);

	return 0;
}