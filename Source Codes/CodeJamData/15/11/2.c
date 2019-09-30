#include <stdio.h>

int main(void) {
	int n_cases;
	int measures[1000];
	scanf("%d", &n_cases);
	for (int i = 0; i < n_cases; ++i) {
		int n_eaten1 = 0;
		int n_eaten2 = 0;
		int eating_rate = 0;
		int n_measures;
		scanf("%d", &n_measures);
		for (int i = 0; i < n_measures; ++i) {
			scanf("%d", &(measures[i]));
		}
		for (int i = 1; i < n_measures; ++i) {
			int diff = measures[i] - measures[i-1];
			if (diff < 0) {
				n_eaten1 += -diff;
				if (eating_rate < -diff) {
					eating_rate = -diff;
				}
			}
		}
		int n_on_plate = measures[0];
		for (int i = 1; i < n_measures; ++i) {
			if (measures[i-1] > eating_rate) {
				n_eaten2 += eating_rate;
				n_on_plate -= eating_rate;
			} else {
				n_eaten2 += measures[i-1];
				n_on_plate -= measures[i-1];
			}
			if (n_on_plate < measures[i]) {
				n_on_plate = measures[i];
			}
		}
		printf("Case #%d: %d %d\n", i+1, n_eaten1, n_eaten2);
	}
}
