#include <stdio.h>

int main() {
	int T;

	int card[2][4][4]; 
	int answer[2]; 
	int solution[4];
	int solutionN;
	int n;
	int i, j;
	int N = 4;
	int t;
	

	scanf("%d", &T);

	for(t = 1; t <= T; t++) {
		solutionN = 0;

		for(n = 0; n < 2; n++) {
			scanf("%d", &answer[n]);
			answer[n]--;
			for(i = 0; i < N; i++) {
				for(j = 0; j < N; j++) {
					scanf("%d", &card[n][i][j]);
				}
			}
				
		}
		for(i = 0;i < N; i++) {
			for(j = 0; j < N; j++) {
				if(card[0][answer[0]][i] == card[1][answer[1]][j]) {
					solution[solutionN++] = card[1][answer[1]][j];
				}
			}
		}
		if(solutionN == 0) {
			printf("Case #%d: Volunteer cheated!\n", t);
		}
		else if(solutionN == 1) {
			printf("Case #%d: %d\n", t, solution[0]);
		}
		else {
			printf("Case #%d: Bad magician!\n", t);
		}
	}

}
