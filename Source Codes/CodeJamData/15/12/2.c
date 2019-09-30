#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

void solve_testcase(int tc) {
	int n_barbers;
	int place_in_line;
	int haircut_duration[1000];
	int ttw[1000];
	int smallest_ttw;
	int smallest_ttw_idx;
	int cycle_duration;
	static short cycle[8000000];
	scanf("%d%d", &n_barbers, &place_in_line);
	for (int i = 0; i < n_barbers; ++i) {
		scanf("%d", &(haircut_duration[i]));
		ttw[i] = 0;
	}
	cycle_duration = place_in_line + 2;
	for (int i = 0; i < place_in_line; ++i) {
		smallest_ttw = INT_MAX;
		smallest_ttw_idx = -1;
		for (int j = 0; j < n_barbers; ++j) {
			if (ttw[j] < smallest_ttw) {
				smallest_ttw = ttw[j];
				smallest_ttw_idx = j;
			}
		}
		//printf("%d\n", smallest_ttw_idx + 1);
		cycle[i] = smallest_ttw_idx + 1;
		ttw[smallest_ttw_idx] += haircut_duration[smallest_ttw_idx];
		int cycle_has_ended = 1;
		for (int j = 1; j < n_barbers; ++j) {
			if (ttw[j] != ttw[0]) {
				cycle_has_ended = 0;
			}
		}
		if (cycle_has_ended) {
			cycle_duration = i+1;
			break;
		}
	}
	printf("Case #%d: %d\n", tc,
			cycle[(place_in_line-1) % cycle_duration]);
}

int main(void) {
	int n_cases;
	scanf("%d", &n_cases);
	for (int i = 0; i < n_cases; ++i) {
		solve_testcase(i+1);
	}
	return 0;
}
