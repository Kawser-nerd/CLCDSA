#include <stdio.h>

typedef struct {
	int i, j, k;
} Rec;

int main(void) {
	int i, j, k;
	int t, c;

	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		int J, P, S, K;
		Rec choice[27];
		int ans_num, ans_choice;

		fprintf(stderr, "Case #%d\n", c);
		fflush(stderr);

		scanf("%d %d %d %d", &J, &P, &S, &K);

		for (i = 0; i < J; i++)
			for (j = 0; j < P; j++)
				for (k = 0; k < S; k++)
					choice[i * P * S + j * S + k] = (Rec){i, j, k};

		ans_num = -1;
		for (i = 0; i < 1 << J * P * S; i++) {
			int cnt[64] = {0};
			int num;

			num = 0;
			for (j = 0; j < J * P * S; j++)
				if (i >> j & 1)
					if (cnt[choice[j].i * 16 + choice[j].j * 4 + choice[j].k] == 0 && cnt[choice[j].i * 16 + choice[j].j * 4 + 3] < K && cnt[48 + choice[j].j * 4 + choice[j].k] < K && cnt[choice[j].i * 16 + 12 + choice[j].k] < K) {
						num++;
						cnt[choice[j].i * 16 + choice[j].j * 4 + choice[j].k]++;
						cnt[choice[j].i * 16 + choice[j].j * 4 + 3]++;
						cnt[48 + choice[j].j * 4 + choice[j].k]++;
						cnt[choice[j].i * 16 + 12 + choice[j].k]++;
					} else
						break;
			if (j == J * P * S)
				if (num > ans_num) {
					ans_num = num;
					ans_choice = i;
				}
		}

		printf("Case #%d: %d\n", c, ans_num);
		for (i = 0; i < J * P * S; i++)
			if (ans_choice >> i & 1)
				printf("%d %d %d\n", choice[i].i + 1, choice[i].j + 1, choice[i].k + 1);
	}

	return 0;
}
