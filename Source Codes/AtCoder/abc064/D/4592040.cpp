#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;
char par[101];
int length, score, min_score;

int main(void) {
	scanf("%d", &length);
	scanf("%s", par);
	score = 0; min_score = 0;
	for (int i = 0; i < length; i++) {
		if (par[i] == '(') {
			score += 1;
		}
		else {
			score -= 1;
		}
		if (min_score > score) {
			min_score = score;
		}
	}
	for (int i = 0; i < -min_score; i++) {
		printf("(");
	}
	printf("%s", par);
	for (int i = 0; i < score - min_score; i++) {
		printf(")");
	}
}