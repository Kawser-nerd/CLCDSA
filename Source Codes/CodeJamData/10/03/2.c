#include <stdio.h>

typedef struct {
	int size;
	int new_index;
	int mark;
	int profit;
} group_t;

#define NMAX 1000
static group_t G[NMAX];

int main() {
	int tc, cs;
	int rounds, cap, n, i, j, c, mu, lambda;
	long long s, s1, profit, mu_sum, lambda_sum;

	scanf("%d", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%d%d%d", &rounds, &cap, &n);
		for (i = 0; i != n; ++i)
			scanf("%d", &G[i].size);

		j = 0;
		s = 0;
		for (i = 0; i != n; ++i) {
			while (j-i != n && (s1 = s + G[j%n].size) <= cap) {
				s = s1;
				++j;
			}

			G[i].new_index = j%n;
			G[i].profit = s;
			G[i].mark = -1;

			s-= G[i].size;
		}

		i = 0;
		c = 0;
		while (G[i].mark < 0) {
			G[i].mark = c++;
			i = G[i].new_index;
		}
		mu = G[i].mark;
		lambda = c - mu;

		if (rounds <= mu) {
			s = 0;
			i = 0;
			for (c = rounds; c != 0; --c) {
				s+= G[i].profit;
				i = G[i].new_index;
			}

			profit = s;
			goto print_answer;
		}

		s = 0;
		i = 0;
		for (c = mu; c != 0; --c) {
			s+= G[i].profit;
			i = G[i].new_index;
		}
		mu_sum = s;

		s = 0;
		for (c = lambda; c != 0; --c) {
			s+= G[i].profit;
			i = G[i].new_index;
		}
		lambda_sum = s;

		profit = mu_sum + (rounds-mu)/lambda*lambda_sum;
		for (c = (rounds-mu)%lambda; c != 0; --c) {
			profit+= G[i].profit;
			i = G[i].new_index;
		}

print_answer:
		printf("Case #%d: %lld\n", cs+1, profit);
	}

	return 0;
}


